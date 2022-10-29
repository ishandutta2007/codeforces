#include <bits/stdc++.h>
using namespace std;

struct pt {
    int x, y, id;
};

struct cmp_x {
    bool operator()(const pt & a, const pt & b) const {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
};

struct cmp_y {
    bool operator()(const pt & a, const pt & b) const {
        return a.y < b.y;
    }
};

int n;
vector<pt>a;

double mindist;
pair<int, int>best_pair;

void upd_ans(const pt & a, const pt & b) {
	
    double dist = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    if(a.id/4 == b.id/4){
    	dist=1e18;
    }
    if (dist < mindist) {
        mindist = dist;
        
        best_pair = {a.id, b.id};
     
    }
}


vector<pt>t;

void rec(int l, int r) {
    if (r - l <= 3) {
        for (int i = l; i < r; ++i) {
            for (int j = i + 1; j < r; ++j) {
                upd_ans(a[i], a[j]);
            }
        }
        sort(a.begin() + l, a.begin() + r, cmp_y());
        return;
    }

    int m = (l + r) >> 1;
    int midx = a[m].x;
    rec(l, m);
    rec(m, r);

    merge(a.begin() + l, a.begin() + m, a.begin() + m, a.begin() + r, t.begin(), cmp_y());
    copy(t.begin(), t.begin() + r - l, a.begin() + l);

    int tsz = 0;
    for (int i = l; i < r; ++i) {
        if (abs(a[i].x - midx) < mindist) {
            for (int j = tsz - 1; j >= 0 && a[i].y - t[j].y < mindist; --j)
                upd_ans(a[i], t[j]);
            t[tsz++] = a[i];
        }
    }
}


int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int N;
	scanf("%d",&N);
	
	n=4*N;
	
	for(int i=0; i<N; i++){
		int c, d;
		scanf("%d%d",&c,&d);
		pt f;
		f.x=c;
		f.y=d;
		f.id=4*i;
		a.push_back(f);
		f.x=-c;
		f.y=d;
		f.id=4*i+1;
		a.push_back(f);
		f.x=c;
		f.y=-d;
		f.id=4*i+2;
		a.push_back(f);
		f.x=-c;
		f.y=-d;
		f.id=4*i+3;
		a.push_back(f);
	}
	t.resize(n);
	sort(a.begin(), a.end(), cmp_x());
	mindist = 1E20;
	rec(0, n);
	int f=best_pair.first;
	int s=best_pair.second;
	
	int val=f%4;
	int ans2=0;
	if(val==0){
		ans2=4;
	}
	if(val==1){
		ans2=3;
	}
	if(val==2){
		ans2=2;
	}
	if(val==3){
		ans2=1;
	}
	
	int val2=s%4;

	printf("%d %d %d %d\n",(f/4)+1,ans2,(s/4)+1,val2+1);
	return 0;
}