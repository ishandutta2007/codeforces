    #include<bits/stdc++.h>
    using namespace std;
    int sufs[100010],suft[100010];
    int nums[100010],numt[100010];
    char  s[100010],t[100010];
    int main(){
    	cin>>s>>t;
    	int n=strlen(s),m=strlen(t),q,a,b,c,d;
    	for(int i=0;i<n;i++)
    		if(s[i]=='A')sufs[i]=sufs[i-1]+1,nums[i]=nums[i-1];
    		else nums[i]=nums[i-1]+1;
    	for(int i=0;i<m;i++)
    		if(t[i]=='A')suft[i]=suft[i-1]+1,numt[i]=numt[i-1];
    		else numt[i]=numt[i-1]+1;
    	cin>>q;
    	for(int i=1;i<=q;i++){
    		scanf("%d%d%d%d",&a,&b,&c,&d),a--,b--,c--,d--;
    		int ss=min(sufs[b],b-a+1),st=min(suft[d],d-c+1);
    		int t1=nums[b]-nums[a-1],t2=numt[d]-numt[c-1];
    		if(ss==b-a+1&&st!=d-c+1){
    			ss--,t1+=2;
    			if(ss>st) ss=st;
    		}
    		if(ss<st)putchar('0');
    		else {
    			if((ss-st)%3)t1+=2,ss=st;
    			if(t1<=t2&&(t1-t2)%2==0)putchar('1');
    			else putchar('0');
    		}
    	}
    	return 0;
    }