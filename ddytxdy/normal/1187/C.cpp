    #include<bits/stdc++.h>
    using namespace std;
    const int N=2000;
    int n,m,ll[N],rr[N],tot,tt,c[N],ans[N];
    struct node{
    	int l,r,k;
    	void init(){scanf("%d%d%d",&k,&l,&r);r--;}
    	bool friend operator <(node a,node b){
    		return a.l<b.l;
    	}
    }a[N],b[N];
    bool cmp(node a,node b){
    	return a.r<b.r;
    }
    int main(){
    	scanf("%d%d",&n,&m);
    	for(int i=1;i<=m;i++)a[i].init();
    	sort(a+1,a+m+1);
    	int la=-1;
    	for(int i=1;i<=m;i++){
    		if(!a[i].k){b[++tt]=a[i];continue;}
    		if(a[i].l>la+1)rr[tot]=la,ll[++tot]=a[i].l;
    		la=max(la,a[i].r);
    	}
    	rr[tot]=la;la=-1;    
    	for(int i=1,j=1;i<=tt;i++){
    		while(rr[j]<b[i].l&&j<tot)j++;
    		if(b[i].r<=rr[j]&&b[i].l>=ll[j])puts("NO"),exit(0);
    		if(b[i].l<=la&&b[i].r>=la)continue;
    		if(rr[j]<b[i].l||ll[j]>b[i].r)c[b[i].l]++,la=b[i].l;
    		else if(b[i].l<ll[j])c[ll[j]-1]++,la=ll[j]-1;
    		else c[rr[j]+1]++,la=rr[j]+1;
    	}
    	puts("YES");
    	ans[n+1]=1;
    	for(int i=n;i;i--)ans[i]=ans[i+1]+c[i];
    	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    	return 0;
    }