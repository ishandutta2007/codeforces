#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];

map<char,char>H;
string s;
int main(){
    H['3']='3';
    H['4']='6';
    H['5']='9';
    H['6']='4';
    H['7']='7';
    H['8']='0';
    H['9']='5';
    H['0']='8';

    cin>>s;
    int flag = 1;
    for(int i=0;i<s.size();i++)
	{
        if(!H.count(s[i]))flag=0;
        else
		{
            if(H[s[i]]!=s[s.size()-1-i])
                flag=0;
        }
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}