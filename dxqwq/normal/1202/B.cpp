#pragma GCC optimize(2)
#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
int num[10][10][10]={0,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,1,2,3,4,5,6,7,8,0,-1,0,-1,1,-1,2,-1,3,-1,0,6,3,0,7,4,1,8,5,2,0,-1,2,-1,0,-1,3,-1,1,-1,0,-1,-1,-1,-1,0,-1,-1,-1,-1,0,-1,1,-1,3,-1,0,-1,2,-1,0,2,5,8,1,4,7,0,3,6,0,-1,3,-1,2,-1,1,-1,0,-1,0,8,7,6,5,4,3,2,1,0,0,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,4,0,0,1,1,2,2,3,3,4,3,0,1,0,1,2,1,2,3,2,3,0,1,2,0,1,2,3,1,2,1,0,1,2,3,0,1,2,3,4,4,0,1,2,3,4,0,1,2,3,3,0,1,2,1,2,3,0,1,2,2,0,1,2,2,3,1,2,0,1,1,0,1,2,3,4,3,2,1,0,0,-1,0,-1,1,-1,2,-1,3,-1,4,0,0,1,1,2,2,3,3,4,4,-1,0,-1,1,-1,2,-1,3,-1,3,3,0,0,1,1,1,2,2,2,2,-1,0,-1,0,-1,1,-1,1,-1,1,3,0,4,1,0,2,1,3,2,2,-1,0,-1,1,-1,0,-1,1,-1,4,2,0,3,1,4,2,0,3,1,1,-1,0,-1,1,-1,1,-1,0,-1,2,1,0,2,1,3,2,2,1,0,0,6,3,0,7,4,1,8,5,2,3,0,1,0,1,2,1,2,3,2,3,3,0,0,1,1,1,2,2,2,9,6,3,0,7,4,1,8,5,2,2,2,2,0,0,3,1,1,1,2,1,2,3,0,3,0,1,4,1,2,4,3,1,0,3,2,0,4,2,1,1,2,3,0,1,4,1,0,3,2,4,1,3,0,2,4,1,3,0,2,3,2,1,0,3,2,1,2,1,0,0,-1,2,-1,0,-1,3,-1,1,-1,3,0,1,2,0,1,2,3,1,2,2,-1,0,-1,0,-1,1,-1,1,-1,2,2,2,0,0,3,1,1,1,2,4,-1,2,-1,0,-1,3,-1,1,-1,1,4,2,2,0,0,3,3,1,1,1,-1,1,-1,0,-1,0,-1,1,-1,4,1,2,4,0,2,3,0,1,3,2,-1,1,-1,0,-1,1,-1,0,-1,4,3,2,1,0,4,3,2,1,0,0,-1,-1,-1,-1,0,-1,-1,-1,-1,1,0,1,2,3,0,1,2,3,4,1,3,0,4,1,0,2,1,3,2,1,2,3,0,3,0,1,4,1,2,1,4,2,2,0,0,3,3,1,1,1,-1,-1,-1,-1,0,-1,-1,-1,-1,1,1,1,3,3,0,0,2,2,4,1,2,1,4,1,0,3,0,3,2,1,2,3,1,2,0,1,4,0,3,1,4,3,2,1,0,3,2,1,0,0,-1,1,-1,3,-1,0,-1,2,-1,4,0,1,2,3,4,0,1,2,3,2,-1,0,-1,1,-1,0,-1,1,-1,4,3,1,0,3,2,0,4,2,1,1,-1,1,-1,0,-1,0,-1,1,-1,1,1,1,3,3,0,0,2,2,4,4,-1,1,-1,3,-1,0,-1,2,-1,2,2,1,1,1,3,0,0,2,2,2,-1,1,-1,1,-1,0,-1,0,-1,3,2,1,3,2,1,0,2,1,0,0,2,5,8,1,4,7,0,3,6,3,0,1,2,1,2,3,0,1,2,4,2,0,3,1,4,2,0,3,1,1,2,3,0,1,4,1,0,3,2,4,1,2,4,0,2,3,0,1,3,1,2,1,4,1,0,3,0,3,2,2,2,1,1,1,3,0,0,2,2,9,2,5,8,1,4,7,0,3,6,3,2,2,2,1,1,1,0,0,3,3,2,3,2,1,2,1,0,1,0,0,-1,3,-1,2,-1,1,-1,0,-1,2,0,1,2,2,3,1,2,0,1,1,-1,0,-1,1,-1,1,-1,0,-1,4,1,3,0,2,4,1,3,0,2,2,-1,1,-1,0,-1,1,-1,0,-1,1,2,3,1,2,0,1,4,0,3,2,-1,1,-1,1,-1,0,-1,0,-1,3,2,2,2,1,1,1,0,0,3,4,-1,3,-1,2,-1,1,-1,0,-1,4,4,3,3,2,2,1,1,0,0,0,8,7,6,5,4,3,2,1,0,1,0,1,2,3,4,3,2,1,0,2,1,0,2,1,3,2,2,1,0,3,2,1,0,3,2,1,2,1,0,4,3,2,1,0,4,3,2,1,0,1,4,3,2,1,0,3,2,1,0,3,2,1,3,2,1,0,2,1,0,3,2,3,2,1,2,1,0,1,0,4,4,3,3,2,2,1,1,0,0,9,8,7,6,5,4,3,2,1,0};
int main() {
	ios::sync_with_stdio(false);
	string str;
	cin>>str;
	int a,ans;
	for(int j=0; j<10; j++)
	{
		for(int k=0; k<10; k++) 
		{
			ans=0;
			for(int i=1; i<str.size(); i++) 
			{
				a=str[i]-str[i-1];
				if(a<0) a+=10;
				if(num[j][k][a]==-1) 
				{
					ans=-1;
					break;
				} 
				else ans+=num[j][k][a];
			}
			cout<<ans<<' ';
		}
		cout<<endl;
	}
	return 0;
}