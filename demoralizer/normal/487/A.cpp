#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int pw(int a,int b,int p){
    if(b==0)return 1;
    int t=pw(a,b/2,p);
    if(b%2)return (((a*t)%p)*t)%p;
    else return ((t*t)%p);
}

int a,b,c,d,e,f,g,h,ii;
int check(int a,int b,int c){
    int x=b-f,y=e-c;
    if(y<=0){
        return 1;
    }
    int p=(d+x-1)/x,q=(a+y-1)/y;
    if(p<q)return 1;
    return 0;
}
void solve(){
    cin>>a>>b>>c>>d>>e>>f>>g>>h>>ii;
    int cost=0;
    while(1){
        int x=b-f,y=e-c;
        if(x<=0){
            b++;
            cost+=h;
        }
        else break;
    }
    int mm=-1;
    for(int i=a;i<1002;i++){
        for(int j=b;j<201;j++){
            for(int k=c;k<101;k++){
                if(!check(i,j,k))continue;
                int cc=g*(i-a)+h*(j-b)+ii*(k-c);
                if(mm==-1)mm=cc;
                mm=min(mm,cc);
                break;
            }
            if(check(i,j,c))break;
        }
        if(check(i,b,c))break;
    }
    cout<<(cost+mm);
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}