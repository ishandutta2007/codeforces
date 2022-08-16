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
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,a=0,d=0;char c;cin>>n;
    for(int i=0;i<n;i++){
        cin>>c;
        if(c=='A')a++;else d++;
    }
    if(a==d)cout<<"Friendship";
    if(a>d)cout<<"Anton";
    if(a<d)cout<<"Danik";
}