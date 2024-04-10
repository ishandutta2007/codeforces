#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=1010;
int n,num1,num2;
char s1[MAXN],s2[MAXN],t[MAXN],ret[MAXN];
mt19937 rnd(time(NULL));
char rev(char s){
    if(s=='T')return 'F';
    else return 'T';
}
ll qry(char* s){
    cout<<(s+1)<<endl;
    ll tmp;cin>>tmp;
    if(tmp==n)exit(0);
    return tmp;
}
ll qry(char* s,int num,vector<int>p){
    ll x=p.size();
    rep(i,1,n)t[i]=s[i];
    for(auto u:p)t[u]=rev(t[u]);
    ll tmp=qry(t);
    ll y=tmp-num;
    return (x-y)/2;
}
void solve(){
    rep(i,1,n)s1[i]='T';
    rep(i,1,n)s2[i]=((odd(i))?('T'):('F'));
    num1=qry(s1);num2=qry(s2);
    int cur=1;
    while(cur<=n){
        if(cur+2>n){
            if(qry(s1,num1,{cur}))ret[cur]='T';
            else ret[cur]='F';
            cur++;
            continue;
        }
        int val=qry(s1,num1,{cur,cur+1});
        if(val==2){ret[cur]=ret[cur+1]='T';cur+=2;}
        else if(val==0){ret[cur]=ret[cur+1]='F';cur+=2;}
        else{
            rep(j,1,n)t[j]=s2[j];
            rep(j,cur,cur+2)t[j]=rev(t[j]);
            int diff=qry(t)-num2;
            if(odd(cur)){
                if(diff==-3)ret[cur]=ret[cur+2]='T',ret[cur+1]='F';
                else if(diff==-1)ret[cur]='T',ret[cur+1]=ret[cur+2]='F';
                else if(diff==3)ret[cur+1]='T',ret[cur]=ret[cur+2]='F';
                else ret[cur+1]=ret[cur+2]='T',ret[cur]='F';
            }else{
                if(diff==-3)ret[cur]=ret[cur+2]='F',ret[cur+1]='T';
                else if(diff==-1)ret[cur]='F',ret[cur+1]=ret[cur+2]='T';
                else if(diff==3)ret[cur+1]='F',ret[cur]=ret[cur+2]='T';
                else ret[cur+1]=ret[cur+2]='F',ret[cur]='T';
            }
            cur+=3;
        }
    }
}
int main(){
    cin>>n;
    solve();
    cout<<(ret+1);
    return 0;
}