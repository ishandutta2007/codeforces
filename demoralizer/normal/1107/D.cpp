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
#define piii              pair<int,pii>
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

int zz[6000];
char xx[5300][5300];
void solve(){
    int n;
    cin>>n;
    //vc<int> v[n];
    map<char,string> m;
    m['0']="0000";m['1']="0001";m['2']="0010";m['3']="0011";
    m['4']="0100";m['5']="0101";m['6']="0110";m['7']="0111";
    m['8']="1000";m['9']="1001";m['A']="1010";m['B']="1011";
    m['C']="1100";m['D']="1101";m['E']="1110";m['F']="1111";
    string s[n];
    for(int i=0;i<n;i++){
        string t;
        cin>>t;
        for(char c:t)s[i]+=m[c];
    }
    int ans=1;int gg=n;
    for(int i=0;i<n;i++){
        int c=1;char w=s[i][0];
        for(int j=1;j<n;j++){
            if(s[i][j]==w)c++;
            else{
                gg=gcd(gg,c);
                c=1;
                w=s[i][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        int c=1;char w=s[0][i];
        for(int j=1;j<n;j++){
            if(s[j][i]==w)c++;
            else{
                gg=gcd(gg,c);
                c=1;
                w=s[j][i];
            }
        }
    }
    cout<<gg;
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