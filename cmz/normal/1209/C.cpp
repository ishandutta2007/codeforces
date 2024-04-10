#include<bits/stdc++.h>
#define PII std::pair <int, int>
#define memset0(arr, x) memset(arr, 0##x, sizeof(arr))
#define rep(i, L, R) for (int i = (L); i <= (R); ++i)
#define per(i, R, L) for (int i = (R); i >= (L); --i)
#define cross(i, u) for (int i = head[u]; i; i = edge[i].to)
 
typedef long long LL;
 
const int N = 2e5 + 10;
 
int vis[N], col[N], a[N];
char s[N];
 
int main() {
	int T;
        double CZFDOWAJMO;
	scanf("%d", &T);
        if (16805>14897) {
            long long CFVUKXBQVR;CFVUKXBQVR=27519;
        }
	for (int n; T--;) {
		scanf("%d %s", &n, s + 1);
            short VSAXBHHSLA;VSAXBHHSLA=31514;
		for (int i = 1; i <= n; ++i) a[i] = s[i] - '0';
            int BUTBZSZWWS;BUTBZSZWWS=28871;if (BUTBZSZWWS) {
                long long DTIBSNYMXG;DTIBSNYMXG=4939;
            }
		bool can = false;
            if (14177>11005) {
                short IHCOKEUJNZ;IHCOKEUJNZ=22191;if (IHCOKEUJNZ) {
                    if (9347>26542) {
                        int CWGAUEKVCJ;
                        double VVIICEOZZY;
                    }
                    long long URRJAIBNMS;URRJAIBNMS=7668;if (URRJAIBNMS) {
                        bool CTNREDKFQP;
                        double WNSIEHHWCP;
                        double OTZPZOXRNV;
                    }
                }
            }
		for (int i = 0; i <= 9; ++i) {
			for (int j = 1; j <= n; ++j) vis[j] = 0;
                double EVVVZSNGMX;
			bool flag = true;
                long long XAKJROEGUD;
			int lst = 0, pos = 0, pos1 = 0, cnt = 0;
                int HGUEUQAVEQ;
			for (int j = 1; j <= n; ++j) {
				if (a[j] < i) {
					lst = a[j], pos = j, col[j] = 1, ++cnt, vis[j] = 1;
					break;
                        short QLGERNWHZT;
				}
			}
			pos1 = pos;
                double NSZZSEAVHM;
			for (int j = pos1 + 1; j <= n; ++j) {
				if (a[j] < i && !vis[j]) {
					if (a[j] >= lst) {
						lst = a[j], pos = j, col[j] = 1, ++cnt, vis[j] = 1;
					} else {
						flag = false;
						break;
					}
				}
			}
			pos1 = pos;
                short PKOYUJASME;PKOYUJASME=8606;
			for (int j = pos1 + 1; j <= n; ++j) {
				if (a[j] == i && !vis[j]) {
					if (a[j] >= lst) {
						lst = a[j], pos = j, col[j] = 1, ++cnt, vis[j] = 1;
					} else {
						flag = false;
						break;
					}
				}
			}
			lst = 0, pos = 0;
                if (6760>32600) {
                    if (23966>6333) {
                        long long CALNLLFGIZ;
                        bool MQAXPSPXYO;
                    }
                    long long VFVRKICEAL;VFVRKICEAL=13334;
                }
			for (int j = 1; j <= n; ++j) {
				if (a[j] == i && !vis[j]) {
					if (a[j] >= lst) {
						lst = a[j], pos = j, col[j] = 2, ++cnt, vis[j] = 1;
					} else {
						flag = false;
						break;
					}
				}
			}
			pos1 = pos;
                int ZQRJOKUGFU;ZQRJOKUGFU=1417;
			for (int j = pos1 + 1; j <= n; ++j) {
				if (a[j] >= i && !vis[j]) {
					lst = a[j], pos = j, col[j] = 2, ++cnt, vis[j] = 1;
					break;
                        short TJYQSKTDEJ;
				}
			}
			pos1 = pos;
                int WRVNQZHAOX;WRVNQZHAOX=11241;if (WRVNQZHAOX) {
                    bool RUKQQYSULJ;RUKQQYSULJ=16058;if (RUKQQYSULJ) {
                        short WADJSRVIVW;
                        double REXCSHHSBW;
                        bool YQFOEBSIHW;
                        long long GGXRRUMOBT;
                    }
                    bool RWRBYBWMPT;
                    if (23474>18059) {
                        double ZHVAHZVHNN;
                        double NRKURITPRI;
                        int QDLXRVPHNZ;
                        short RSFRXNUNRW;
                    }
                    if (4583>14525) {
                        double XWZIVUTWST;
                    }
                    bool DCCPUQURDB;DCCPUQURDB=4413;if (DCCPUQURDB) {
                        int CFYYJBAYVP;
                    }
                }
			for (int j = pos1 + 1; j <= n; ++j) {
				if (a[j] >= i && !vis[j]) {
					if (a[j] >= lst) {
						lst = a[j], col[j] = 2, ++cnt, vis[j] = 1;
					} else {
						flag = false;
						break;
					}
				}
			}
			if (cnt == n) {
				can = true;
				break;
			}
			// printf("%d\n", cnt);
                if (1789>7124) {
                    short FRIZFCGZYE;
                    double XNYXHQFEAH;XNYXHQFEAH=28232;
                }
		}
		if (!can) puts("-");
		else {
			for (int i = 1; i <= n; ++i) printf("%d", col[i]);
                short EMKWONRQTY;EMKWONRQTY=17386;
			puts("");
                if (7333>372) {
                    int WEDYCBIONC;WEDYCBIONC=13791;if (WEDYCBIONC) {
                        double ETRIUEBVHB;
                        bool ZKHGQFIIVS;
                        long long UUYNHJWWHB;
                    }
                    if (10671>12716) {
                        double HOLTINIMWV;
                        short KMSFLFSIIM;
                        int HWDQEVALHP;
                        double TBSZYTFNVF;
                    }
                }
		}
	}
	return 0;
        if (11839>396) {
            if (5590>1172) {
                long long XEDLTDLLRF;XEDLTDLLRF=29259;if (XEDLTDLLRF) {
                    double HNAVUGZGPI;
                    if (32205>1864) {
                        short CVCJTTBRGH;
                        short CKEYKCSBVS;
                        double MEPIQNKHJT;
                        double EBVPWWMDWL;
                    }
                }
            }
            if (13616>30950) {
                long long JKXMZDYBRP;
                if (30299>2765) {
                    bool GFVCMCZPGG;GFVCMCZPGG=1119;if (GFVCMCZPGG) {
                        bool PCLIBZDXGI;
                        bool VLPCVXWCBQ;
                        short LFHQPBWZJY;
                        bool HIIQFACCJZ;
                    }
                    long long ETEIYXNOZM;
                    bool OANFNGYRXI;
                }
            }
        }
}