#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    int q[k];
    for(int a=0; a<k; a++) q[a]=0;
    for(int a=0; a<n; a++) q[s[a]-'A']++;
    int mi=1e9;
    for(int a=0; a<k; a++) mi=min(mi, q[a]);
    cout<<mi*k;

}