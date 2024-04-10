#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a[100005];
    int i=0;
    string s;
    cin >> s;
    for(int j=0; j<s.size(); j++){
        while(s[j]>a[i-1] && i>0){
            i--;
        }
        a[i++]=s[j];
    }
    for(int j=0; j<i; j++){
        cout << a[j];
    }
	return 0;
}