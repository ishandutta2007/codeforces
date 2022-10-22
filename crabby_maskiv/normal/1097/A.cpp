#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int maxn=100005;
const int inf=0x3f3f3f3f;
int n,m;
string s;
char t[1005];
int main()
{
	int i,j;
	cin>>s;
	getchar();
	cin.getline(t,1000);
	if(t[0]==s[0]||t[1]==s[1]||t[3]==s[0]||t[4]==s[1]||t[6]==s[0]||t[7]==s[1]||t[9]==s[0]||t[10]==s[1]||t[12]==s[0]||t[13]==s[1])
		cout<<"YES";
	else cout<<"NO";
	return 0;
}