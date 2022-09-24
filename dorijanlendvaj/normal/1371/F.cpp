#include <bits/stdc++.h>

using namespace std;

using no=array<int,11>;

const int N=500010,M=1<<19;
int t,n,q;
string h;
no seg[M*2+10];
bool pro[M*2+10];

no mer(no a,no b)
{
	no res;
	if (b[4]==b[8]) res[0]=b[0]+a[0];
	else if (b[0]==b[8]) res[0]=b[0]+a[6];
	else res[0]=b[0];
	if (a[7]==a[8]) res[1]=a[1]+b[1];
	else if (a[1]==a[8]) res[1]=a[1]+b[5];
	else res[1]=a[1];
	if (b[6]==b[8]) res[2]=b[2]+a[2];
	else if (b[2]==b[8]) res[2]=b[2]+a[4];
	else res[2]=b[2];
	if (a[5]==a[8]) res[3]=a[3]+b[3];
	else if (a[3]==a[8]) res[3]=a[3]+b[7];
	else res[3]=a[3];
	if (b[4]==b[8]) res[4]=b[4]+a[4];
	else res[4]=b[4];
	if (a[5]==a[8]) res[5]=a[5]+b[5];
	else res[5]=a[5];
	if (b[6]==b[8]) res[6]=b[6]+a[6];
	else res[6]=b[6];
	if (a[7]==a[8]) res[7]=a[7]+b[7];
	else res[7]=a[7];
	res[8]=a[8]+b[8];
	res[9]=max(max(a[9],b[9]),max(a[4]+b[3],a[2]+b[7]));
	res[10]=max(max(a[10],b[10]),max(a[6]+b[1],a[0]+b[5]));
	return res;
}

void pr(int i)
{
	if (!pro[i]) return;
	seg[i]={seg[i][2],seg[i][3],seg[i][0],seg[i][1],seg[i][6],seg[i][7],seg[i][4],seg[i][5],seg[i][8],seg[i][10],seg[i][9]};
	if (i<M)
	{
		pro[i*2]^=1;
		pro[i*2+1]^=1;
	}
	pro[i]=0;
}

void upd(int l,int r,int lo=0,int hi=M,int i=1)
{
	if (lo>=l && hi<=r)
	{
		pro[i]^=1;
		pr(i);
		return;
	}
	pr(i);
	if (lo>=r || hi<=l) return;
	int mid=(lo+hi)/2;
	upd(l,r,lo,mid,i*2);
	upd(l,r,mid,hi,i*2+1);
	seg[i]=mer(seg[i*2],seg[i*2+1]);
}

no ge(int l,int r,int lo=0,int hi=M,int i=1)
{
	pr(i);
	if (lo>=l && hi<=r) return seg[i];
	if (lo>=r || hi<=l) return {0,0,0,0,0,0,0,0,0,0,0};
	int mid=(lo+hi)/2;
	return mer(ge(l,r,lo,mid,i*2),ge(l,r,mid,hi,i*2+1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q>>h;
	for (int i=0;i<n;++i)
	{
		if (h[i]=='<') seg[i+M]={1,1,1,1,0,0,1,1,1,1,1};
		else seg[i+M]={1,1,1,1,1,1,0,0,1,1,1};
	}
	for (int i=M-1;i;--i) seg[i]=mer(seg[i*2],seg[i*2+1]);
	while (q--)
	{
		int l,r;
		cin>>l>>r;
		--l;
		upd(l,r);
		auto re=ge(l,r);
		cout<<re[9]<<'\n';
	}
}