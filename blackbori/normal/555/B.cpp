#include <bits/stdc++.h>

using namespace std;

struct bridge{
	int i;
	long long a;
};

struct island{
	int i;
	long long s,e;
};

struct que{
	int i;
	long long e;
    bool operator<(const que &o) const
    {
        return e > o.e;
    }
};

vector <bridge> B;
vector <island> I;
priority_queue <que> Q;
int Idx[200003];

bool comp1(island a,island b)
{
	return a.s>b.s;
}

bool comp2(bridge a,bridge b)
{
	return a.a<b.a;
}

int N,M;

int main()
{
	scanf("%d %d",&N,&M);
	long long a,b,aa,bb;
	int i;
	island k;
	scanf("%lld %lld",&a,&b);
	for(i=1; i<N; i++){
		scanf("%lld %lld",&aa,&bb);
		k.s=aa-b, k.e=bb-a; k.i=i;
		I.push_back(k);
		a=aa; b=bb;
	}
	
	bridge kk;
	for(i=0; i<M; i++){
		scanf("%lld",&kk.a);
		kk.i=i+1; B.push_back(kk);
	}
	
//	for(i=0; i<N-1; i++) printf("%d %lld %lld\n",I[i].i,I[i].s,I[i].e);
//	for(i=0; i<M; i++) printf("%d %lld\n",B[i].i,B[i].a);
	
	sort(I.begin(), I.end(), comp1);
	sort(B.begin(), B.end(), comp2);	
	
	que k3;
	for(i=0; i<M; i++){
		while(!I.empty() && I.back().s <= B[i].a){
			k3.i = I.back().i; k3.e=I.back().e;
			Q.push(k3);
			I.pop_back();
		}
//		printf("%d %lld\n",i,Q.size());
		if(!Q.empty() && Q.top().e < B[i].a) break;
		if(!Q.empty()){
//			printf("%lld\n",Q.top().e);
			Idx[Q.top().i] = B[i].i, Q.pop();
		}
	}
	
	if(!Q.empty() || !I.empty()) printf("No\n");
	else{
		printf("Yes\n");
		for(i=1; i<N; i++) printf("%d ",Idx[i]);
		printf("\n");
	}
	
	return 0;
	}