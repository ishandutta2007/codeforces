#include<bits/stdc++.h>
using namespace std;
//a
//v 
//l 
//w 
//d 
int main()
{
	double tmp,ans;
	double a,v,l,d,w;
	cin>>a>>v>>l>>d>>w;
	if(w<=v)  
	{
		tmp=w*w/2/a;//  
		
        if(tmp<d)//  
        {  
            //  
            ans = sqrt(2*tmp/a);  
            double dis=d-tmp;  
            dis/=2;  
            if((v*v-w*w)/2/a <= dis)//  
            {  
                double t = (v-w)/a;  
                t+=(dis-(v*v-w*w)/2/a)/v;  
                ans+=2*t;  
                tmp=d;  
            }  
            else  //  
            {  
                double t = sqrt(2*(tmp+dis)/a)-ans;  
                ans+=2*t;  
                tmp=d;  
            }
        }
        else if(tmp>=d &&tmp<=l)    
        {  
            ans=sqrt(2*tmp/a);  
        }  
        else if(tmp>l)  
        {  
            ans=sqrt(2*l/a);  
            tmp=l;  
        }  
  
        if(tmp<l)  
        {  
            double dis = (v*v-w*w)/2/a;  
            if(tmp+dis<=l)  
            {  
                ans+=(v-w)/a;  
                ans+=(l-tmp-dis)/v;  
            }  
            else  
            {  
                ans+=(sqrt(2*a*(l-tmp)+w*w)-w)/a;  
           	}  
        }  
	}
	
	else  
    {  
        tmp=v*v/2/a;  
        if(tmp<l)  
        {  
            ans=sqrt(2*tmp/a)+(l-tmp)/v;  
        }  
        else if(tmp>l)  
        {  
            ans=sqrt(2*l/a);  
        }  
    }  
    printf("%.5lf\n",ans);
	return 0;
}