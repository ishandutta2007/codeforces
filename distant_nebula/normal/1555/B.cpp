#include <cstdio>
#include <algorithm>
int T, W, H, a, b, w, h, ans;
int main()
{
	int x1, y1, x2, y2;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &W, &H);
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		scanf("%d%d", &w, &h);
		a=x2-x1, b=y2-y1;
		ans=0x3f3f3f3f;
		if(w+a<=W) ans=std::min(ans, std::min(w-x1, x2-(W-w)));
		if(h+b<=H) ans=std::min(ans, std::min(h-y1, y2-(H-h)));
		ans=std::max(ans, 0);
		printf("%d\n", ans==0x3f3f3f3f?-1:ans);
	}
	return 0;
}