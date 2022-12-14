#include <cstdio>
#include <cstring>

long long cx[64], cy[64], cxx[64], cxy[64], cyx[64], cyy[64];
int k, x, n, m;

char s[1024], t[1024];

int main()
{
	scanf("%d %d %d %d", &k, &x, &n, &m);
	
	cx[1] = 1;
	cy[2] = 1;
	cx[3] = cy[3] = cxy[3] = 1;
	for (int i = 4; i <= k; ++i)
	{
		cx[i] = cx[i-1] + cx[i-2];
		cy[i] = cy[i-1] + cy[i-2];
		cxx[i] = cxx[i-1] + cxx[i-2];
		cxy[i] = cxy[i-1] + cxy[i-2];
		cyx[i] = cyx[i-1] + cyx[i-2];
		cyy[i] = cyy[i-1] + cyy[i-2];
		if (i&1)
			++cyy[i];
		else
			++cyx[i];
	}
	//~ printf("%lld %lld %lld %lld __ %d\n", cx[k], cy[k], cxx[k], cxy[k], x);
	//~ printf("%lld %lld %lld %lld __ %d\n", cx[k], cy[k], cyx[k], cyy[k], x);
	
	for (long long acx = 0; acx*2 <= n; ++acx)
	{
		for (long long acy = 0; acy*2 <= m; ++acy)
		{
			for (long long xbc = 0; xbc < 2; ++xbc)
			{
				for (long long xea = 0; xea < 2; ++xea)
				{
					for (long long ybc = 0; ybc < 2; ++ybc)
					{
						for (long long yea = 0; yea < 2; ++yea)
						{
							if ((acx*cx[k] + acy*cy[k] + cyx[k]*(xbc==yea&&xbc==1)
								+ cyy[k]*(yea==ybc&&yea==1) + cxx[k]*(xbc==xea&&xbc==1)
								+ cxy[k]*(ybc==xea&&ybc==1)) == x)
							{
								//~ printf("EQ %lld %d (%lld %lld ; %lld)\n", (acx*cx[k] + acy*cy[k] + cyx[k]*(xbc==yea)
								//~ + cyy[k]*(yea==ybc) + cxx[k]*(xbc==xea)
								//~ + cxy[k]*(ybc==xea)), x, acx, acy, cy[k]);
								memset(s, 0, sizeof(s));
								memset(t, 0, sizeof(t));
								if (n == 1 && xbc && xea) continue;
								if (m == 1 && ybc && yea) continue;
								if (xbc) s[0] = 'C';
								if (xea) s[n-1] = 'A';
								if (ybc) t[0] = 'C';
								if (yea) t[m-1] = 'A';
								
								int j = 0;
								for (int i = 0; i < n; i++)
								{
									if (s[i] == 0)
									{
										if (j < acx && s[i+1] == 0 && i+1 < n)
										{
											s[i] = 'A';
											s[i+1] = 'C';
											++j;
										}
										else
											s[i] = 'N';
									}
								}
								if (j == acx)
								{
									j = 0;
									for (int i = 0; i < m; i++)
									{
										if (t[i] == 0)
										{
											if (j < acy && t[i+1] == 0 && i+1 < m)
											{
												t[i] = 'A';
												t[i+1] = 'C';
												++j;
											}
											else
												t[i] = 'N';
										}
									}
									if (j == acy)
									{
										s[n] = '\0';
										t[m] = '\0';
										//~ printf("sl %lld %lld :: %lld %lld %lld %lld\n", acx, acy, xbc, xea, ybc, yea);
										printf("%s\n%s\n", s, t);
										return 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	
	printf("Happy new year!\n");
	return 0;
}