#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
    bool operator <(const node z)const{
        if(l==z.l)return r<z.r;
        return l<z.l;
    }
}b[200005];
void work(){
    vector<vector<int>>A;
    int n,m,i,j,k,s=0;
    scanf("%d%d",&n,&m);
    A.resize(n+5);
    for(i=1;i<=n;++i)A[i].resize(m+5);
    for(i=1;i<=n;++i)for(j=1;j<=m;++j)scanf("%d",&A[i][j]);
    vector<int>B;
    for(i=1;i<=n;++i){
        B.clear();
        for(j=2;j<=m;++j){
            if(A[i][j-1]>A[i][j])B.push_back(j-1);
        }
        if(B.size()==1){
            j=B[0];
            for(k=j+1;A[i][k]==A[i][j+1]&&k<=m;++k);
            --k;
            swap(A[i][j],A[i][k]);
            bool flg=1;
            for(int ii=2;ii<=m;++ii){
                if(A[i][ii-1]>A[i][ii]){
                    flg=0;
                    break;
                }
            }
            swap(A[i][j],A[i][k]);
            ++s;
            if(flg){
                b[s].l=j;
                b[s].r=k;
            }
            else{
                for(k=j;A[i][k]==A[i][j]&&k;--k);
                ++k;
                b[s].l=k;
                b[s].r=j+1;
                //printf("%d %d\n",k,j+1);
            }
        }
        else if(B.size()==2){
            ++s;
            b[s].l=B[0];
            b[s].r=B[1]+1;
        }
        else if(B.size()>=3){
            puts("-1");
            return;
        }
    }
    //printf("%d %d\n",b[1].l,b[1].r);
    for(i=2;i<=s;++i){
        if(b[i].l!=b[i-1].l||b[i].r!=b[i-1].r){
            puts("-1");
            return;
        }
    }
    if(s==0){
        puts("1 1");
        return;
    }
    int L=b[1].l,R=b[1].r;
    for(i=1;i<=n;++i)swap(A[i][L],A[i][R]);
    for(i=1;i<=n;++i){
        for(j=2;j<=m;++j){
            if(A[i][j-1]>A[i][j]){
                puts("-1");
                return;
            }
        }
    }
    printf("%d %d\n",L,R);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}