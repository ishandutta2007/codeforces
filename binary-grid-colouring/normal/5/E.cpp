#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000010;
int H[maxn], L[maxn], R[maxn], C[maxn];
int n;
/*
 
LR
First hill to the left of the x, which is strictly higher than x.
First hill to the right of the x, which is strictly higher than x.
C
All hills that are as high as x and are located between x and y.
L[i]ii()
R[i]ii()
C[i]i R[i]i
L R C

i L[i]  R[i]pairi R[i]ipair
 LR C
*/ 
int main()
{
    scanf("%d",&n);  
    for (int i = 0; i < n; i++)
	{
		scanf("%d",&H[i]);//cinT 
	} 			    
    rotate(H, max_element(H, H + n), H + n);
    //5 3 1 2 4
    H[n] = H[0];
    for (int i = n - 1; i >= 0; --i)
	{
		R[i] = i+1;
		while(R[i] < n && H[R[i]] < H[i])
		{
			R[i] = R[R[i]];
		}   
		 
        if (R[i] < n && H[R[i]] == H[i])
		{
        	C[i] = C[R[i]] + 1;
			R[i] = R[R[i]];
		}
		
    }
    //for(int i=0;i<=n;i++)printf("L[%d]=%d ",i,L[i]);cout<<endl;
   // for(int i=0;i<=n;i++)printf("R[%d]=%d ",i,R[i]);cout<<endl;
    //for(int i=0;i<=n;i++)printf("C[%d]=%d ",i,C[i]);cout<<endl;
    ll ans = 0;
    for (int i = 0; i < n; i++)
	{
        ans += C[i];
        if (H[i] == H[0]) continue;
        
        L[i] = i - 1;
        while(L[i] > 0 && H[L[i]] <= H[i])
        {
        	L[i] = L[L[i]];
		}
        ans += 2;
        if (L[i] == 0 && R[i] == n)
		{
        	ans--;
		}
    }
    //for(int i=0;i<=n;i++)printf("L[%d]=%d ",i,L[i]);cout<<endl;
    printf("%I64d\n",ans);
    return 0;
}