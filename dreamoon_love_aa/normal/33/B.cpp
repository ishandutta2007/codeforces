#include<stdio.h>
#include<string.h>
#define SIZE 100010
char s1[SIZE],s2[SIZE],an[26][26];
int a[26][26],d[26][26];
main(){
    int n,i,j,k,x;
    char c1[8],c2[8];
    scanf("%s%s",s1,s2);
    scanf("%d",&n);
    for(i=0;i<26;i++)
        for(j=0;j<26;j++)a[i][j]=-1;
    while(n--){
        scanf("%s%s%d",c1,c2,&x);
        if(a[c1[0]-'a'][c2[0]-'a']<0||a[c1[0]-'a'][c2[0]-'a']>x)
            a[c1[0]-'a'][c2[0]-'a']=x;
    }
    for(i=0;i<26;i++)a[i][i]=0;
    for(k=0;k<26;k++)
        for(i=0;i<26;i++)
            if(a[i][k]!=-1)
                for(j=0;j<26;j++)
                    if(a[k][j]!=-1)
                        if(a[i][j]==-1||a[i][j]>a[i][k]+a[k][j])a[i][j]=a[i][k]+a[k][j];
    for(i=0;i<26;i++)
        for(j=0;j<26;j++){
            d[i][j]=-1;
            for(k=0;k<26;k++){
                if(a[i][k]<0||a[j][k]<0)continue;
                if(d[i][j]==-1||d[i][j]>a[i][k]+a[j][k]){
                    d[i][j]=a[i][k]+a[j][k];
                    an[i][j]='a'+k;
                }
            }
        }
    if(strlen(s1)!=strlen(s2)){
        puts("-1");
    }
    else{
        k=0;
        for(i=0;s1[i];i++){
            if(d[s1[i]-'a'][s2[i]-'a']<0)break;
            k+=d[s1[i]-'a'][s2[i]-'a'];
            s1[i]=an[s1[i]-'a'][s2[i]-'a'];
        }
        if(s1[i])puts("-1");
        else printf("%d\n%s\n",k,s1);
    }
}