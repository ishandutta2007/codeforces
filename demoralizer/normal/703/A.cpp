#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define msi map<string,int>
#define mii map<int,int>
#define psi pair<string,int>
#define pis pair<int,string>
#define piii pair<int,pii>
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}


int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    int m=0,c=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(a>b)m++;
        if(b>a)c++;
    }
    if(m>c)cout<<"Mishka";
    else if(m<c)cout<<"Chris";
    else cout<< "Friendship is magic!^^";
}