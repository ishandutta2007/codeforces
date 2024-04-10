#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 500005;
int k, n, cnt;
double sum, b[N];
vector<double> f[N];
struct wish{
	int x, y;
	wish operator-()const{ return (wish){-x, -y};}
	wish operator-(const wish &r)const{ return (wish){x-r.x, y-r.y};}
	wish operator+(const wish &r)const{ return (wish){x+r.x, y+r.y};}
	void operator-=(const wish &r){ x-=r.x, y-=r.y;}
	void operator+=(const wish &r){ x+=r.x, y+=r.y;}
	bool operator<(const wish &r)const{ return x<r.x || (x==r.x && y<r.y);}
	double len(){ return sqrt((ll)x*x+(ll)y*y);}
} a[N];
ll cross(const wish &a, const wish &b){ return (ll)a.x*b.y-(ll)a.y*b.x;}
bool cmp(const wish &a, const wish &b){
	bool x=a.y>0 || (!a.y && a.x>0), y=b.y>0 || (!b.y && b.x>0);
	return x^y?x:cross(a, b)>0;
}
vector<double> operator*(const vector<double> &x, const vector<double> &y){
	int i=0, j=0;
	vector<double> ans;
	while(i<(int)x.size() || j<(int)y.size())
		if(j>=(int)y.size() || (i<(int)x.size() && x[i]>y[j]))
			ans.push_back(x[i++]);
		else ans.push_back(y[j++]);
	return ans;
}
vector<double> solve(int l, int r){
	if(l==r) return f[l];
	int mid=(l+r)>>1;
	return solve(l, mid)*solve(mid+1, r);
}
int main() {
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; ++i){
		scanf("%d%d", &a[i].x, &a[i].y);
		if(!a[i].x && !a[i].y) --i, --n;
	}
	sort(a+1, a+n+1, cmp);
	for(int i=1; i<=n; ++i){
		int j=i;
		while(j<n && !cmp(a[i], a[j+1]) && !cmp(a[j+1], a[i])) ++j;
		++cnt;
		for(int x=i; x<=j; ++x) b[x]=a[x].len();
		sort(b+i, b+j+1);
		for(int x=j; x>=i && k-(j-x)*2-1>0; --x) f[cnt].push_back((k-(j-x)*2-1)*b[x]);
		if(j-i+1>n/2){
			int c=k-(n-j+i)-k/2;
			b[i-1]=0;
			for(int x=0; x<c; ++x) sum+=(b[i+x]-b[i+x-1])*((ll)(k/2+c-x)*(k-k/2-c+x)-(ll)k/2*(k-k/2));
		}
		i=j;
	}
	auto ans=solve(1, cnt);
	for(int i=0; i<k && i<(int)ans.size(); ++i) sum+=ans[i];
	printf("%.8lf\n", sum);
	return 0;
}