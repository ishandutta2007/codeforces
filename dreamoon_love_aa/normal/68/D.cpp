#include<stdio.h>
double max(double x,double y){return x>y?x:y;}
struct node{
    node *left,*right;
    int e,left_sum,right_sum;
}*root;
void add(node *&ptr,int two,int v,int e){
    if(two==0){
        ptr->e+=e;
        return;
    }
    if(v&two){
        if(ptr->right==NULL){
            ptr->right=new node;
            ptr->right->e=ptr->right->left_sum=ptr->right->right_sum=0;
            ptr->right->left=ptr->right->right=NULL;
        }
        ptr->right_sum+=e;
        add(ptr->right,two>>1,v,e);

    }
    else{
        if(ptr->left==NULL){
            ptr->left=new node;
            ptr->left->e=ptr->left->left_sum=ptr->left->right_sum=0;
            ptr->left->left=ptr->left->right=NULL;
        }
        ptr->left_sum+=e;
        add(ptr->left,two>>1,v,e);
    }
}
double query(node *&ptr,double ma){
    double an=0;
    if(ptr->left==NULL&&ptr->right==NULL)return max(ma,ptr->e);
    if(ptr->left_sum + ptr->e >= ptr->right_sum)an+=0.5*max(ma,(ptr->left_sum + ptr->e));
    else an+=0.5*query(ptr->right,max(ma,ptr->left_sum + ptr->e));
    if(ptr->right_sum + ptr->e >= ptr->left_sum)an+=0.5*max(ma,(ptr->right_sum + ptr->e));
    else an+=0.5*query(ptr->left,max(ma,ptr->right_sum + ptr->e));
    return an;
}
main(){
    root=new node;
    root->left=root->right=NULL;
    root->e=root->left_sum=root->right_sum=0;
    char s[8];
    int h,q,x,y,i;
    scanf("%d%d",&h,&q);
    while(q--){
        scanf("%s",s);
        if(s[0]=='a'){
            scanf("%d%d",&x,&y);
            for(i=1;(x>>1)>=i;i<<=1);
            add(root,i>>1,x,y);
        }
        else{
            printf("%.8lf\n",query(root,0));
        }
    }
}