#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];
//brainfuck
string s;
string solve(int p)
{
    if(p==0)
	{
        return "0";
    }
    int flag = 0;
    if(p<0) 
	{
		flag=1;
		p=-p;
	}
    string tmp;
    while(p)
	{
        tmp+=(p%10+'0');
        p/=10;
    }
    if(flag)tmp+='-';
    reverse(tmp.begin(),tmp.end());
    return tmp;
}
int main()
{
    cin>>s;
    int now = 0;
    int num = 0;
    int flag = 0;
    for(int i=0;i<s.size();i++)
	{
        if(s[i]=='+'||s[i]=='-')
		{
            if(flag==0)
			{
                now+=num;
            }
            else{
                now-=num;
            }
            if(s[i]=='+'){
            	flag=0;
			}
            else flag=1;
            num=0;
        }
		else
		{
            num=num*10+(s[i]-'0');
        }
    }
    if(flag==0)
	{
        now+=num;
    }
    else
	{
        now-=num;
    }
    string ss = solve(now); 
    for(int i=0;i<ss.size();i++)
	{
        for(int j=0;j<ss[i];j++)
		{
            cout<<"+";
        }
        cout<<".";
        cout<<">"<<endl;
    }
    return 0;
}