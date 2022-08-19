//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,f[10][10],u[10][10],X[100],Y[100],cnt,ans,lax[10][10],lay[10][10],d[10][10];
int dx[10]={-2,-1,1,2,2,1,-1,-2};
int dy[10]={1,2,2,1,-1,-2,-2,-1};
string out[2222];
void mak(int a,int b,int c,int d){
    string s="";
    s+=(char)(96+a);
    s+=(char)(48+b);
    s+='-';
    s+=(char)(96+c);
    s+=(char)(48+d);
    out[++ans]=s;
}
void go(int x,int y){
    memset(d,-1,sizeof(d));
    queue<int> qx,qy;
    qx.push(x);
    qy.push(y);
    d[x][y]=1;
    while(!qx.empty()){
        int x=qx.front(),y=qy.front();
        qx.pop(),qy.pop();
        if(f[x][y]){
            cnt=d[x][y];
            for(int i=cnt;i;--i){
                X[i]=x,Y[i]=y;
                int p=lax[x][y],q=lay[x][y];
                x=p,y=q;
            }
            return;
        }
        for(int k=0;k<8;++k){
            int p=x+dx[k],q=y+dy[k];
            if(p<1||p>8||q<1||q>8||u[p][q]||d[p][q]!=-1) continue;
            d[p][q]=d[x][y]+1,lax[p][q]=x,lay[p][q]=y;
            qx.push(p),qy.push(q);
        }
    }
}
void solve(){
    for(int i=1;i<=n;++i){
        char c;
        int x;
        cin>>c>>x;
        f[c-96][x]=1;
    }
    int t=n;
    for(int j=1;j<=8;++j){
        for(int i=1;i<=8;++i){
            if(!t){
                j=10;
                break;
            }
            --t;
            cnt=0;
            go(i,j);
            f[X[cnt]][Y[cnt]]=0;
            u[i][j]=1;
            for(int k=cnt;k>1;--k)mak(X[k],Y[k],X[k-1],Y[k-1]);
        }
    }
}
           
void solve2(){
    for(int i=1;i<=8;++i){
        for(int j=1;j<=8;++j)f[i][j]=1;
    }
    for(int i=1;i<=n;++i){
        char c;
        int x;
        cin>>c>>x;
        f[c-96][x]=0;
    }
    int t=64-n;
    for(int j=8;j>0;--j){
        for(int i=8;i;--i){
            if(!t){
                j=0;
                break;
            }
            --t;
            cnt=0;
            go(i,j);
            f[X[cnt]][Y[cnt]]=0;
            u[i][j]=1;
            for(int k=cnt;k>1;--k)mak(X[k-1],Y[k-1],X[k],Y[k]);
        }
    }
}            
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    if(n<=32)solve();
    else solve2();
    cout<<ans<<endl;
    for(int i=1;i<=ans;++i)cout<<out[i]<<endl;
//	system("pause");
	return 0;
}