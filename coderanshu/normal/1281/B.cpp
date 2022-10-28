#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))
#define rep(i,a,b) for(i=a;i<b;i++)

ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b%m,(e-1)/2,m)%m;
	else
		return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b,(e-1)/2);
	else
		return power(b*b,e/2);
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a,b;
	ll t,k,l,i,found;
	bool done;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		done=false;
		k=min(a.length(),b.length());
		for(i=0;i<k;i++)
		{
			if(a[i]<b[i])
			{
				done=true;
				break;
			}
			else if(a[i]==b[i])
			{
				 for(l=i;l<a.length();l++)
				 {
				 	if(a[l]<a[i])
				 	{
				 		swap(a[l],a[i]);
				 		done=true;
				 		break;
				 	}
				 }
				 if(done)break;
			}
			else
			{
				found=0;
				for(l=i;l<a.length();l++)
				{
					if(a[l]<b[i])
					{
						found=1;
						swap(a[l],a[i]);
						done=true;
						break;
					}
				}
				if(found==0)
				{
					for(l=a.length()-1;l>=i;l--)
					{
						if(a[l]==b[i])
						{
							found=1;
							swap(a[l],a[i]);
							break;
						}
					}
					if(!found)
					{
						done=false;break;
					}
					else
					{
						i++;
						for(l=i;l<k;l++)
						{
							if(a[l]<b[l])
							{
								done=true;break;
							}
							if(a[l]==b[l])
							{
								i++;
							}
							if(a[l]>b[l])
							{
								done=false;break;
							}
						}
						break;
					}
				}
				if(found)
				{
					break;
				}
			}

		}
		if(i==k)
		{
			if(a.length()<b.length())
			{
				done=true;
			}
			else
				done=false;
		}
		if(done)cout<<a<<"\n";
		else
			cout<<"---\n";
	}
	return 0;
}