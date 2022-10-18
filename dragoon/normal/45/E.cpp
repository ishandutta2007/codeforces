#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
/*
bool cmp1(string A, string B)
{
	len1 = A.size();
	len2 = B.size();
	len = MIN(len1,len2);

	if(A.substr(len) < B.substr(len)) return 1;
	if(A.substr(len) > B.substr(len)) return 0;

	if(len1 < len2) return 1;
	return 0;
}
*/

vector<string> A, B;
int cnt1[300],cnt2[300];
int over, ans;
int done[300];

#define MIN(A,B) ((A)<(B)?(A):(B))


int check()
{
	int now = over;
	int i;

	for(i='A';i<='Z';i++) 
		now += MIN(cnt2[i], cnt1[i]);
	
	if(now != ans) return 0;
	return 1;
}

int main()
{
	int n,j,i;
	char name[40];

	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",name);
		A.push_back(name);
		cnt1[name[0]]++;
	}

	for(i=0;i<n;i++)
	{
		scanf("%s",name);
		B.push_back(name);
		cnt2[name[0]]++;
	}

	ans = 0;
	for(i='A';i<='Z';i++)
		ans += MIN(cnt1[i], cnt2[i]);

	sort(A.begin(),A.end());
	sort(B.begin(),B.end());

	over = 0;
	for(i=0;i<n;i++)
	{
		if(i) printf(", ");
		printf("%s",A[i].c_str());
		cnt1[A[i][0]]--;

		for(j=0;j<n;j++) if(done[j]) continue;
		else
		{
			cnt2[B[j][0]]--;
			if(B[j][0]==A[i][0]) over++;
			if(!check())
			{
				if(B[j][0]==A[i][0]) over--;
				cnt2[B[j][0]]++;
				continue;
			}
			done[j]=1;
			printf(" %s",B[j].c_str());
			break;
		}
	}

	printf("\n");

	return 0;
}