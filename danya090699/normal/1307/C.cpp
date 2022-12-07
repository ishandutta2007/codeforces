#include <bits/stdc++.h>
using namespace std;
long long q[26][26], q2[26];
main()
{
	//freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    for(int a=0; a<s.size(); a++)
    {
        int sy=s[a]-'a';
        for(int i=0; i<26; i++) q[i][sy]+=q2[i];
        q2[sy]++;
    }
    long long an=0;
    for(int i=0; i<26; i++)
    {
        an=max(an, q2[i]);
        for(int j=0; j<26; j++) an=max(an, q[i][j]);
    }
    cout<<an;
}