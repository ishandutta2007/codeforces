#include <cstdio>
#include <cstring>

const int MAXN = 10000;

struct tank
{
	int hp, dt, l, r, p, oh;
};

tank v, o;

void readtank(tank& t)
{
	scanf("%d %d %d %d %d", &t.hp, &t.dt, &t.l, &t.r, &t.p);
}

double vhpr[MAXN + 20][22];
double ohpr[MAXN + 20][22];

void gethpr(tank v, double hpr[1 << 20][22])
{
	memset(hpr, 0, sizeof(vhpr));
	hpr[0][0] = 1.0;
	for (int i = 0; i <= MAXN; ++i)
	{
		for (int j = 0; j <= 20; ++j)
		{
			hpr[i + 1][j] += hpr[i][j] * (double) v.p / 100.0;
			int nj = j + 1;
			if (nj > 20)
				nj = 20;
			hpr[i + 1][nj] += hpr[i][j] * (double) (100.0 - v.p) / 100.0;
		}
	}
}

double vpkill[22][256];
double opkill[22][256];

void getpkill(tank v, double pkill[22][256])
{
	memset(pkill, 0, sizeof(vpkill));
	pkill[0][0] = 1.0;
	for (int i = 0; i <= 20; ++i)
	{
		double len = v.r - v.l + 1;
		for (int dmg = v.l; dmg <= v.r; ++dmg)
		{
			for (int h = 0; h <= v.oh; ++h)
			{
				int nh = h + dmg;
				if (nh > v.oh)
					nh = v.oh;
				pkill[i + 1][nh] += pkill[i][h] / len;
			}
		}
	}
}

int main()
{
	readtank(v);
	readtank(o);
	v.oh = o.hp;
	o.oh = v.hp;
	
	gethpr(v, vhpr);
	gethpr(o, ohpr);
	getpkill(v, vpkill);
	getpkill(o, opkill);
	double ans = 0;
	int i = 1;
	int j = 0;
	double pkpr = 0.0;
	//~ printf("%lf\n", vhpr[1][1]);
	//~ printf("%lf\n", vhpr[2][2]);
	//~ printf("%lf\n", vhpr[3][3]);
	//~ printf("\n");
	//~ printf("%lf\n", vpkill[1][v.oh]);
	//~ printf("%lf\n", vpkill[2][v.oh]);
	//~ printf("%lf\n", vpkill[3][v.oh]);
//~ 
	//~ printf("\n\n");
	//~ printf("%lf\n", ohpr[1][1]);
	//~ printf("%lf\n", ohpr[2][2]);
	//~ printf("%lf\n", ohpr[3][3]);
	//~ printf("\n");
	//~ printf("%lf\n", opkill[1][o.oh]);
	//~ printf("%lf\n", opkill[2][o.oh]);
	//~ printf("%lf\n", opkill[3][o.oh]);
	while (i <= MAXN && j <= MAXN)
	{
		double vkpr, okpr;
		vkpr = 0.0;
		okpr = 0.0;
		//~ printf("SOL %d %d %lf\n", i, j, pkpr);
		for (int k = 0; k <= 20; ++k)
		{
			vkpr += vhpr[i][k] * vpkill[k][v.oh];
			okpr += ohpr[j][k] * opkill[k][o.oh];
		}
		ans += (vkpr - pkpr) * (1.0 - okpr);
		pkpr = vkpr;
		++i;
		while (j <= MAXN && (j - 1) * o.dt < (i - 1) * v.dt)
			++j;
		--j;
	}
	printf("%.10lf\n", ans);
	return 0;
}