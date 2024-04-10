#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m,s,f;
	scanf("%d%d%d%d",&n,&m,&s,&f);
	vector<int> t(m+1),l(m+1),r(m+1);
	for(int i=0;i<m;i++) scanf("%d%d%d",&t[i],&l[i],&r[i]);
	t[m]=l[m]=r[m]=1000000000;
    int idx=0;
    int now=1;
    while(s!=f)
    {
        if(s<f)
        {
            if(now==t[idx])
            {
                if((l[idx]<=s&&s<=r[idx])||(l[idx]<=s+1&&s+1<=r[idx])) printf("X");
                else
                {
                    printf("R");
                    s++;
                }
                idx++;
            }
            else
            {
                printf("R");
                s++;
            }
        }
        else
        {
            if(now==t[idx])
            {
                if((l[idx]<=s&&s<=r[idx])||(l[idx]<=s-1&&s-1<=r[idx])) printf("X");
                else
                {
                    printf("L");
                    s--;
                }
                idx++;
            }
            else
            {
                printf("L");
                s--;
            }
        }
        now++;
    }
	return 0;
}