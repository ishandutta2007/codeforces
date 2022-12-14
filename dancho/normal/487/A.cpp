#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int hy, ay, dy;
	int hm, am, dm;
	int h, a, d;
	scanf("%d %d %d", &hy, &ay, &dy);
	scanf("%d %d %d", &hm, &am, &dm);
	scanf("%d %d %d", &h, &a, &d);
	
	int bans = (1 << 29);
	for (int ab = 0; ab <= 310; ++ab)
	{
		for (int db = 0; db <= 310; ++db)
		{
			int y, m;
			y = hy;
			m = hm;
			if (max(0, ab + ay - dm) <= 0)
			{
				continue;
			}
			while (m > 0)
			{
				y -= max(0, am - (dy + db));
				m -= max(0, ab + ay - dm);
			}
			int hb = 0;
			if (y <= 0)
			{
				hb = -y + 1;
			}
			//~ printf("%d %d\n", y, hb);
			bans = min(bans, hb * h + ab * a + db * d);
		}
	}
	printf("%d\n", bans);
	return 0;
}