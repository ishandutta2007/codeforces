#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    char f;int a=1;
    char s[103];
    cin>>s;
    char c=s[0];
    f=c;
    c=s[1];
    int i=2;
    while(c!='\0'){
        if(c==f)a++;
        else{a=1;f=c;}
        if(a>6){cout<<"YES";r0;}
        c=s[i];
        i++;
    }
    cout<<"NO";
}