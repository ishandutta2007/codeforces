#include<bits/stdc++.h>
using namespace std;
int cnt[2];
bool w[2];
bool win(char c,char s[9])
{
	if(s[0]==c&&s[3]==c&&s[6]==c)return true;
	if(s[1]==c&&s[4]==c&&s[7]==c)return true;
	if(s[2]==c&&s[5]==c&&s[8]==c)return true;
	if(s[0]==c&&s[1]==c&&s[2]==c)return true;
	if(s[3]==c&&s[4]==c&&s[5]==c)return true;
	if(s[6]==c&&s[7]==c&&s[8]==c)return true;
	if(s[0]==c&&s[4]==c&&s[8]==c)return true;
	if(s[2]==c&&s[4]==c&&s[6]==c)return true;
	return false;
}
int main()
{
	char c[9];
	for(int i=0;i<9;i++)
	{
		cin>>c[i];
		if(c[i]=='0')cnt[0]++;
		if(c[i]=='X')cnt[1]++;
	}
	w[0]=win('0',c);
	w[1]=win('X',c);
	if((w[0]&&cnt[0]+1==cnt[1])||(w[1]&&cnt[0]==cnt[1])||(cnt[1]-cnt[0]>1||cnt[1]-cnt[0]<0))
		cout<<"illegal";
	else if(w[0])
		cout<<"the second player won";
	else if(w[1])
		cout<<"the first player won";
	else if(cnt[0]+cnt[1]==9)
		cout<<"draw";
	else if(cnt[0]<cnt[1])
		cout<<"second";
	else
		cout<<"first";
}