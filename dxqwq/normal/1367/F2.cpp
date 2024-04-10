#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
vector<pair<int,int> >v;
set<int> S1,S2;
int main(){
	int T=read();
	while(T--)
	{
		int n=read();
        for(int i=0; i<n; i++) v.pb(mp(read(),-i));
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0,j=0; i<n; i++) 
		{
            if(v[i].first!=v[i-S2.size()].first) 
			{
                for(int x:S2) S1.insert(x);
                S2.clear();
            }
            while(S1.size()&&*S1.begin()<v[i].second) S1.erase(v[j++].second);
            S2.insert(v[i].second),ans=max(ans,(int)S1.size()+(int)S2.size());
        }
        cout<<n-ans<<endl;
        v.clear(),S1.clear(),S2.clear();
	}
	return 0;
}