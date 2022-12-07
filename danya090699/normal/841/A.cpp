//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, q[26], ok=1;
    cin>>n>>k;
    for(int a=0; a<26; a++) q[a]=0;
    for(int a=0; a<n; a++)
    {
        char x;
        cin>>x;
        q[x-'a']++;
    }
    for(int a=0; a<26; a++) if(q[a]>k) ok=0;
    if(ok) cout<<"YES";
    else cout<<"NO";
}