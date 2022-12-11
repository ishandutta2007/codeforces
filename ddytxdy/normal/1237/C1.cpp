#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n;bool vis[N];
struct node{
    int x,y,z,id;
    bool friend operator <(node a,node b){
        if(a.x!=b.x)return a.x<b.x;
        if(a.y!=b.y)return a.y<b.y;
        return a.z<b.z;
    }
}a[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z),a[i].id=i;
    sort(a+1,a+n+1);
	for(int i=1,j;i<=n;i++){
		j=i;
		while(j<n&&a[j+1].x==a[j].x&&a[j+1].y==a[j].y)j++;
		for(int k=i;k<j;k+=2)printf("%d %d\n",a[k].id,a[k+1].id),vis[k]=vis[k+1]=1;
		i=j;
	}
	for(int i=1,j;i<=n;i++){
		j=i;
		while(j<n&&a[j+1].x==a[j].x)j++;
		for(int k=i,l;k<=j;k++){
			while(vis[k])k++;
			l=k+1;
			while(vis[l])l++;
			if(l<=j)printf("%d %d\n",a[k].id,a[l].id),vis[k]=vis[l]=1;
			k=l;
		}
		i=j;
	}
	for(int i=1,j;i<=n;i++){
		while(vis[i])i++;
		j=i+1;
		while(vis[j])j++;
		if(j<=n)printf("%d %d\n",a[i].id,a[j].id);
		i=j;
	}
    return 0;
}