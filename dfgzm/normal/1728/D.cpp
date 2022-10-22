#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
int i,j,k,n,m,is[maxn][maxn];
string S;
int check(int x,int y){
    if(x==y)return 0;
    return x<y?1:-1;
}
int work(int L,int R){
    if(is[L][R]>50)return is[L][R]-100;
    if(R-L==1)return S[L-1]==S[R-1]?0:1;
    int Ans=-1;
    int c1=work(L+2,R),c2=work(L+1,R-1),c3=work(L,R-2);
    int w1=min(c1==0?check(S[L-1],S[L]):c1,c2==0?check(S[L-1],S[R-1]):c2);
    int w2=min(c2==0?check(S[R-1],S[L-1]):c2,c3==0?check(S[R-1],S[R-2]):c3);
    // cerr<<"Work "<<L<<' '<<R<<' '<<is[L][R]<<"    "<<check(S[L-1],S[R-1])<<endl;
    // cerr<<c1<<' '<<c2<<' '<<c3<<" | "<<w1<<' '<<w2<<endl;
    return (is[L][R]=max(w1,w2)+100)-100;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>S;
        for(int i=1;i<=S.size();i++)
            for(int j=i+1;j<=S.size();j++)
                is[i][j]=0;
        int x=work(1,S.size());
        if(x>0)cout<<"Alice"<<endl;
        else if(x<0)cout<<"Bob"<<endl;
        else cout<<"Draw"<<endl;
    }
}