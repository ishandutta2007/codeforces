#include <bits/stdc++.h>
using namespace std;
#define oo 1000000010
#define mod 1000000007
const int N = 500010;

char arr[N];

int n , q;

inline char Not(char x){
	if(x == '>')
		return '<';
	return '>';
}

struct S{
	char a , b;
	int s1 , s2 , l1 , l2;
	int mx[2];
	int all;
	void zero(){
		s1 = s2 = l1 = l2 = mx[0] = mx[1] = all = 0;
	}
	void make(char x){
		mx[0] = mx[1] = 1;
		a = b = x;
		s1 = l1 = 1;
		s2 = l2 = 0;
		all = 1;
	}
	void make2(const S &l , const S &r){
		if(l.s1 + l.s2 == 0){
			(*this) = r;
			return;
		}
		if(r.s1 + r.s2 == 0){
			(*this) = l;
			return;
		}
		mx[0] = max(l.mx[0] , r.mx[0]);
		mx[1] = max(l.mx[1] , r.mx[1]);
		if(l.b == '>'){
			if(r.a == '>')
				mx[0] = max(mx[0] , l.l1 + r.s1 + r.s2) , mx[1] = max(mx[1] , l.l1 + l.l2 + r.s1);
			else
				mx[0] = max(mx[0] , l.l1 + r.s1);
		}
		else{
			if(r.a == '>')
				mx[1] = max(mx[1] , l.l1 + r.s1);
			else
				mx[0] = max(mx[0] , l.l1 + l.l2 + r.s1) , mx[1] = max(mx[1] , l.l1 + r.s1 + r.s2);

		}
		all = l.all + r.all - (l.b == r.a ? 1 : 0);
		s1 = l.s1;
		if(l.s2 == 0){
			if(l.b == r.a){
				s1 += r.s1;
				s2 = r.s2;
			}
			else{
				s2 = r.s1;
			}
		}
		else{
			s2 = l.s2;
			if(l.all < 3 && l.b == r.a)
				s2 += r.s1;
		}
		l1 = r.l1;
		if(r.l2 == 0){
			if(l.b == r.a){
				l1 += l.l1;
				l2 = l.l2;
			}
			else
				l2 = l.l1;
		}
		else{
			l2 = r.l2;
			if(r.all < 3 && l.b == r.a)
				l2 += l.l1;
		}
		a = l.a;
		b = r.b;

	}
	void operator=(const S & other){
		a = other.a , b = other.b;
		mx[0] = other.mx[0] , mx[1] = other.mx[1];
		all = other.all , s1 = other.s1 , s2 = other.s2 , l1 = other.l1, l2 = other.l2;
	}
	void Print(){
		printf("mx[0] = %d , mx[1] = %d\n",mx[0] , mx[1]);
		printf("start with %c, ends with %c\n",a , b);
		printf("(%d,%d)(%d,%d)\n",s1,s2,l1,l2);
		printf("all = %d\n",all);
	}
};

S seg[4 * N];

int lazy[4 * N];

inline void fix(int s,int e,int idx){
	if(lazy[idx] == 1){
		swap(seg[idx].mx[0] , seg[idx].mx[1]);
		seg[idx].a = Not(seg[idx].a);
		seg[idx].b = Not(seg[idx].b);
	}
	if(s != e){
		lazy[(idx << 1)] ^= lazy[idx];
		lazy[(idx << 1) + 1] ^= lazy[idx];
	}
	lazy[idx] = 0;
}

void build(int s,int e,int idx){
	if(s == e){
		seg[idx].make(arr[e]);
		return; 
	}
	build(s, ((s+e) >> 1),(idx << 1));
	build(((s+e) >> 1) + 1,e,(idx << 1) + 1);
	seg[idx].make2(seg[(idx << 1)] , seg[(idx << 1) + 1]);
	//cout << "node in range " << s << " , " << e << endl;
	//seg[idx].Print();
}

int l , r;

void update(int s,int e,int idx){
	fix(s , e , idx);
	if(s > r || e < l)
		return;
	if(s >= l && e <= r){
		lazy[idx] ^= 1;
		fix(s , e , idx);
		//cout << "node in range after update " << s << " , " << e << endl;
		//seg[idx].Print();
		return;
	}
	update(s, ((s+e) >> 1),(idx << 1));
	update(((s+e) >> 1) + 1,e,(idx << 1) + 1);
	seg[idx].make2(seg[(idx << 1)] , seg[(idx << 1) + 1]);
	//cout << "node in range after update " << s << " , " << e << endl;
	//seg[idx].Print();
}

S gt[4 * N];

void get(int s,int e,int idx){
	if(s > r || e < l){
		gt[idx].zero();
		return;
	}
	if(s >= l && e <= r){
		gt[idx] = seg[idx];
		return;
	}
	get(s, ((s+e) >> 1),(idx << 1));
	get(((s+e) >> 1) + 1,e,(idx << 1) + 1);
	gt[idx].make2(gt[(idx << 1)] , gt[(idx << 1) + 1]);

}

int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",arr);
	build(0 , n - 1 , 1);
	while(q--){
		scanf("%d%d",&l,&r);
		l--,r--;
		update(0 , n - 1 , 1);
		get(0 , n - 1 , 1);
		printf("%d\n",gt[1].mx[0]);
	}
	return 0;
}