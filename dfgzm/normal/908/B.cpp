#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int i,j,k,n,m,a[maxn][maxn];
int fx[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int main(){
    cin>>n>>m;
    int X1=0,Y1=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            char c=getchar();
            while(c!='.' && c!='#' && c!='S' && c!='E')c=getchar();
            if(c=='.')a[i][j]=1;
            if(c=='S')a[i][j]=2,X1=i,Y1=j;
            if(c=='E')a[i][j]=3;
        }
    string S;
    cin>>S;
    int Num=0;
    for(int c1=0;c1<4;c1++)
    for(int c2=0;c2<4;c2++)
    for(int c3=0;c3<4;c3++)
    for(int c4=0;c4<4;c4++)
        if(c1!=c2 && c1!=c3 && c1!=c4 && c2!=c3 && c2!=c4 && c3!=c4){
            int x=X1,y=Y1;
            for(j=0;j<S.size();j++){
                if(S[j]=='0')x+=fx[c1][0],y+=fx[c1][1];
                if(S[j]=='1')x+=fx[c2][0],y+=fx[c2][1];
                if(S[j]=='2')x+=fx[c3][0],y+=fx[c3][1];
                if(S[j]=='3')x+=fx[c4][0],y+=fx[c4][1];
                if(a[x][y]==3)break;
                if(!a[x][y])break;
            }
            if(a[x][y]==3)++Num;
        }cout<<Num<<endl;
}