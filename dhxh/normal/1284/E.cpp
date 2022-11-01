#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 3000 + 5;

long long n, m;

struct point {
	long long x, y;
} p[maxn];

long long operator * (point a, point b){
	return a.x * b.y - a.y * b.x;
}

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

long long cross(long long x1, long long y1, long long x2, long long y2){
	return (x1 * y2 - x2 * y1);
}

long long compare(point a, point b, point c){
	return cross((b.x - a.x), (b.y - a.y), (c.x - a.x), (c.y - a.y));
}

int getdir(point a){
	if(a.x >= 0){
		if(a.y >= 0){
			return 1;
		}else{
			return 4;
		}
	}else{
		if(a.y >= 0){
			return 2;
		}else{
			return 3;
		}
	}
}

bool cmp(point a, point b){
	if(getdir(a) != getdir(b)){
		return getdir(a) < getdir(b);
	}else{
		return a * b > 0;
	}
}

long long getans(vector <point> vec){
	int i, j;
	sort(vec.begin(), vec.end(), cmp);
	long long ans = 0;
	long long r = 0, cnt = 0;
	for(i=0;i<vec.size();i++){
		while((r + 1) < i + vec.size() and vec[i] * vec[(r + 1) % vec.size()] >= 0) cnt++, r++;
		ans += cnt * (cnt - 1) / 2;
		cnt--;
	}
	return ans;
}

int main(){
	int i, j;
	long long ans = 0;
	
	n = read();
	
	for(i=1;i<=n;i++){
		p[i].x = read();
		p[i].y = read();
	}
	
	for(i=1;i<=n;i++){
		vector <point> vec;
		for(j=1;j<=n;j++){
			if(i == j)continue;
			vec.push_back({p[j].x - p[i].x, p[j].y - p[i].y});
		}
		ans += 1ll * (1ll * (n - 1) * (n - 2) * (n - 3) / 6 - getans(vec));
	}
	
	printf("%lld\n", ans * (n - 4) / 2);
	
	return 0;
}