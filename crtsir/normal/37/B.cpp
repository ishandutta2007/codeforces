#include<bits/stdc++.h>
using namespace std;
pair<pair<long long,long long>,long long>m[1002];
bool vis[1001];
vector<pair<long long,long long> >ans;
long long reg,n,hea,d,times;
bool cmp(pair<pair<long long,long long>,long long>a,pair<pair<long long,long long>,long long>b){
	return a>b;
}
int main()
{
    cin>>n>>hea>>reg;
    long long t=hea;
    for(long long i=0;i<n;i++)
    {
        scanf("%lld %lld",&m[i].first.second,&m[i].first.first);
        m[i].second=i;
		if(m[i].first.second==100)d+=m[i].first.first;
    }
    sort(m,m+n,cmp);
    if(hea>d&&reg>=d)
    {
        puts("NO");
        return 0;
    }
    d=0;
    while( hea > 0 )
    {
        long long best = 0 , p = 1000;
        for(long long i=0; i<n; i++)
            if(!vis[i]&&m[i].first.second*t>=hea*100&&best<m[i].first.second)
            {
			    best=m[i].first.first,
                p=i;
                break;
            }
        vis [ p ] = true;
        d += best;
        if(p != 1000)
            ans.push_back(make_pair(times,m[p].second+1));
        long long tmp=hea;
        hea = min(hea,hea + reg - d);
        if(times>10000){
        	cout<<"NO";
        	return 0;
		}
        times ++;
    }
    cout<<"YES"<<endl;
    cout<<times<<' '<<ans.size();
    for(long long i=0;i<ans.size();i++)
        printf("\n%lld %lld",ans[i].first,ans[i].second);
}