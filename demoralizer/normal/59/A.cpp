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
    char s[109];
    cin>>s;
    int n=strlen(s),u=0,l=0;
    for(int i=0;i<n;i++){
        if(s[i]<'a')u++;else l++;
    }
    for(int i=0;i<n;i++){
        if(u>l){
            if(s[i]>'Z')s[i]-=32;
        }
        else{
            if(s[i]<'a')s[i]+=32;
        }
        cout<<s[i];
    }
}