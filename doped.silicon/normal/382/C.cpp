
 #include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb() push_back()
#define pp() pop_back()
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n;
    cin>>n;
    if(n==1)
    cout<<"-1";
    else{
    	vector<lli>v;
    	for(lli i=0;i<n;i++)
    	{
    		lli x;
    		cin>>x;
    		v.push_back(x);
    	}
    	sort(v.begin(),v.end());
    	lli a=v[1]-v[0],b=0,a1=1,b1=0,ans=0,temp;
    	bool k=true,f=false,k1=true;
    	if(n==2)
    	{
    		if(v[0]==v[1])
    		{
    			cout<<"1\n"<<v[0];
    		}
    		else if(a%2==0)
    		{
    			cout<<"3\n";
    			cout<<v[0]-a<<" "<<((v[1]+v[0])/2)<<" "<<v[1]+a;
    			
    		}
    		else
    		{cout<<"2\n";
    		cout<<v[0]-a<<" "<<v[1]+a;}
    	}
    	else
    	{
    		for(lli i=2;i<n;i++)
    		{
    			temp=v[i]-v[i-1];
    			if(!f&&temp!=a)
    			{
    				f=true;
    				b1=1;
    				{
    					if(temp==2*a)
    					{
    						
    					b1=1;
    					b=temp;
    					ans=v[i]-temp/2;}
    					else if(temp*2==a){
    						b1=1;
    						b=temp;
    						if(a%2==0)
    	                                             	            {
    	                                             	            	
    			                                      ans=((v[1]+v[0])/2);
    			
    	                                                          	}
    	                                          	            else
    	                                       	            {
    		                                                
    	                                       	             k1=false;	
    	                                       	            }
    					}
    					else{
    				//	cout<<"FAds";
    					k1=false;}
    				}
    			}
    			else if(temp==a)
    			{
    				if(b1>1)
    				k1=false;
    				else
    			    	a1++;	
    			}
    			else if(temp==b)
    			{
    				if(a1>1)
    				k1=false;
    				else
    			    	b1++;	
    			}
    			else
    			k1=false;
    		}
    	//	cout<<f;
    		if(!k1)
    		
    		cout<<"0";
            else if(a1>b1&&b!=0&&a>b)
            {
              cout<<"0";
             }
            else if(b1>a1&&b>a)
             cout<<"0";
    		else if(!k)
    		cout<<"-1";
    		else
    		{
    			if(!f){
    				if(a==0)
    				cout<<"1\n"<<v[0];
    				else{
    				cout<<"2\n";
    				cout<<v[0]-a<<" "<<v[n-1]+a;}
    			}
    			
    			else
    			{cout<<"1\n";
    			cout<<ans;}
    		}
    	}
    }
	return 0;}