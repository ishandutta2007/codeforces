#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sq(x) ((x)*(x))
#define dis2(p1,p2) (sq((p1).x-(p2).x)+sq((p1).y-(p2).y))
#define dis(p1,p2) sqrt(dis2((p1),(p2)))
#define x first
#define y second
struct node{
	pair<int,int>p[2];
	void in(){cin>>p[0].x>>p[0].y>>p[1].x>>p[1].y;}
}seg[3];
int t;
int check_online(int a,int b,int c,int d,int e,int f){
    if((f-b)*(c-a)==(d-b)*(e-a))
        return 1;
    return 0;
}
int check_angle(int x,int y,int a,int b,int p,int q){
    if((a-x)*(p-x)+(b-y)*(q-y)<0)
        return 0;
    return 1;
}
int check_subseg(int x,int y,int m,int n,int a,int b){
    if(x!=a){
        if(a>x){
            if((a-x)*5<(m-x)) 
				return 0;
            if((a-x)*5>(m-x)*4) 
				return 0;
            return 1;
        }
    	else{
       		if((x-a)*5<(x-m)) 
            	return 0;
        	if((x-a)*5>(x-m)*4)
        	    return 0;
        	return 1;
    	}
    }else{
        if(b>y){
            if((b-y)*5<(n-y))
                return 0;
            if((b-y)*5>(n-y)*4)
                return 0;
            return 1;
        }else{
            if((y-b)*5<(y-n))
                return 0;
            if((y-b)*5>(y-n)*4)
                return 0;
            return 1;
        }
    }
}
bool solve(int a,int b,int c){
	pair<int,int>p1,p2,p3;
	for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
			if(seg[a].p[i]==seg[b].p[j]){
				p1=seg[a].p[i],
				p2=seg[a].p[i^1],
				p3=seg[b].p[j^1];
				goto loop;
			}
	return false;
	loop:;
	if(!check_angle(p1.first,p1.second,p2.first,p2.second,p3.first,p3.second))return false;
	for(int i=0;i<=1;i++)
		if(check_online(seg[a].p[0].first,seg[a].p[0].second,
						seg[a].p[1].first,seg[a].p[1].second,
						seg[c].p[i].first,seg[c].p[i].second)
			&&
		   check_online(seg[b].p[0].first,seg[b].p[0].second,
						seg[b].p[1].first,seg[b].p[1].second,
						seg[c].p[i^1].first,seg[c].p[i^1].second)){
			if(!check_subseg(seg[a].p[0].first,seg[a].p[0].second,
							 seg[a].p[1].first,seg[a].p[1].second,
							 seg[c].p[i].first,seg[c].p[i].second))return false;
			if(!check_subseg(seg[b].p[0].first,seg[b].p[0].second,
							 seg[b].p[1].first,seg[b].p[1].second,
							 seg[c].p[i^1].first,seg[c].p[i^1].second))return false;
			return true;
		}
	return false;
}
signed main(){
	cin>>t;
	while(t--){
		seg[0].in();seg[1].in();seg[2].in();
		if(solve(0,1,2)||solve(0,2,1)||solve(1,2,0))
			puts("YES");
		else puts("NO");
	}
	return 0;
}