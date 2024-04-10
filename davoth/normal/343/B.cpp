#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[100005];
    int i=0;
    string s;
    cin >> s;
    for(int j=0; j<s.size(); j++){
        if(i==0) a[i++]=s[j];
        else if(a[i-1]!=s[j]) a[i++]=s[j];
        else i--;
    }
    if(i==0) cout << "Yes";
    else cout << "No";
	return 0;
}