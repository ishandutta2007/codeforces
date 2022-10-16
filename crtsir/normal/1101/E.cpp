#include<bits/stdc++.h>
using namespace std;
int mx,my,T,x,y;char c;
int main(){cin>>T;
	while(T--){cin>>c;
		scanf("%d%d",&x,&y);
		if(x>y)swap(x,y);
		if(c=='+'){
			mx=max(mx,x);
			my=max(my,y);
		}else
			if(mx<=x&&my<=y)
				printf("YES\n");
			else
				printf("NO\n");
	}
}