#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define psi pair<string,int>
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        char c[2000],y;int k=0,z[26];
        cin>>c;
        for(int i=0;i<26;i++){
            z[i]=0;
        }
        y=c[0];
        for(int i=0;i<strlen(c);i++){
            if(y!=c[i])k++;
            z[c[i]-'a']++;
        }
        if(k==0)cout<<-1;
        else{
            for(int i=0;i<26;i++){
                for(int j=0;j<z[i];j++){
                    cout<<(char)('a'+i);
                }
            }
        }
        cout<<"\n";
    }
}