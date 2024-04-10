#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> mp;
int main()
{
    int x1,y1,x2,y2;
    int cnt1=0,cnt2=0;
    for(int i=0;i<4;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        if(x1!=x2&&y1==y2) cnt1++;
        if(x1==x2&&y1!=y2) cnt2++;
        mp[make_pair(x1,y1)]++;
        mp[make_pair(x2,y2)]++;
    }
    bool flag = false;
    if(cnt1==2&&cnt2==2)flag = true;
    for(map<pair<int,int>,int>::iterator i=mp.begin();i!=mp.end();i++)
    {
    	if(i->second!=2){
    		flag =  false;
    		break;
		}
	}
    if(flag) puts("YES");
    else puts("NO");
    return 0;
}