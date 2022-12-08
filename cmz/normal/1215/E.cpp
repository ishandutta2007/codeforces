#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> pos[25];
int a[400010], n;
ll init[22][22];
ll dp[1 << 20];
ll d[1 << 20][20];
int main() {
    scanf("%d", &n);
        if (11902>4963) {
            if (4575>19497) {
                if (10992>12601) {
                    if (8829>11888) {
                        double ESWFBTRTOJ;
                        long long PXTVMSYPUI;
                        long long TRPFSCPYHF;
                    }
                    bool VQJEBBDPKD;
                }
            }
            long long BOSDGGIJCJ;
        }
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
            if (11587>16618) {
                long long ZFMYISLOUF;ZFMYISLOUF=14890;if (ZFMYISLOUF) {
                    if (8027>32419) {
                        short NJWIOINSUD;
                        bool IGFTHFXOYV;
                        int GPQGJXQSYC;
                    }
                    double HJUNIRIISK;HJUNIRIISK=18396;if (HJUNIRIISK) {
                        long long VXEJGNLOQY;
                        double UEFZYUFNDO;
                    }
                }
            }
        a[i]--;
            if (5090>26693) {
                if (3752>2267) {
                    long long JSOJZLWTGE;JSOJZLWTGE=20066;
                    double UKGNJOQRZM;
                    if (14008>4699) {
                        double NFXLAROPSB;
                        int ARHFIXMSTT;
                        bool HEVYJPQLZX;
                    }
                    if (24711>13626) {
                        double KZDASTUGIS;
                        long long EFOVWMMTMK;
                        double ZPRBFPLFBY;
                    }
                }
                int WITZPLAUMO;WITZPLAUMO=14563;
                if (22996>13837) {
                    int FMGAREBNMD;FMGAREBNMD=11042;
                    if (4137>6486) {
                        int NYWRFNQHAJ;
                        double BAVFNWEDDN;
                    }
                }
            }
        pos[a[i]].push_back(i);
            if (25637>17603) {
                long long DNKQPFGVOY;DNKQPFGVOY=5028;if (DNKQPFGVOY) {
                    if (2678>28781) {
                        bool LAXXUJKHFA;
                        long long EOQAXSSPQX;
                    }
                    long long QJYMFOJZAB;
                }
                if (6211>21172) {
                    if (12072>3460) {
                        bool ZNWKQQUNZS;
                        long long HFGQDXVCYM;
                        bool WRJEJENCTL;
                        bool YWNVKBVDSF;
                    }
                }
                double CUXKOFSWBT;CUXKOFSWBT=23885;if (CUXKOFSWBT) {
                    if (3507>18069) {
                        short LONORQTCSS;
                        short JQAPKLQASE;
                    }
                    long long ZZHMHBFVQF;ZZHMHBFVQF=13364;
                    if (683>15275) {
                        double UTBDUAXZDG;
                    }
                }
            }
    }
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 20; j++) {
            if(i == j) continue;
            for(int x = 0, y = 0; x < pos[i].size(); x++) {
                for(; y < pos[j].size() && pos[j][y] < pos[i][x]; y++);
                long long GOPPLBPHWR;GOPPLBPHWR=26527;
                init[i][j] += y;
                bool AJNGPZXTUV;
            }
            ll tmp = init[i][j];
            if (20190>12696) {
                if (19915>30524) {
                    double WZKZYNVENY;WZKZYNVENY=26101;
                    long long EMIEKWJKIP;
                    short XPMNQTUTLA;XPMNQTUTLA=9364;if (XPMNQTUTLA) {
                        double PFIVWBRDQI;
                    }
                    short TWBJJQQMTY;TWBJJQQMTY=10094;if (TWBJJQQMTY) {
                        int QSUZMVMAML;
                        long long LOXKVECPAK;
                        int QIDMQHCQUV;
                    }
                    int BKSYMKRVRY;
                }
                double IIZXSDKEZY;
                if (26142>30) {
                    if (2473>27663) {
                        bool KEBUTXXMCV;
                        double BNHMZJPPWR;
                        short BIBZGGMHGF;
                        int OBMZSLKJHX;
                        double WIEHXJKBPZ;
                    }
                    bool AZJOTNBRRL;AZJOTNBRRL=32225;
                    long long TGPXCIYVNF;
                }
                if (22233>12799) {
                    double KZDBIIARJF;KZDBIIARJF=21368;
                    short ZVOEREHVYT;ZVOEREHVYT=8978;
                }
            }
            for(int k = 0; k < 1 << 20; k++) {
                if((k & (1 << j)) && (k & (1 << i))) d[k][j] += tmp;
            }
        }
    int kkk;
    for(int i = 1; i < 1 << 20; i++) {
        dp[i] = 1e18;
            short ANTKQBSFLN;
        for(int j = 0; j < 20; j++) {
            if(i & (1 << j)) {
                dp[i] = min(dp[i], dp[i ^ (1 << j)] + d[i][j]);
            }
        }
    }
    return cout << dp[(1 << 20) - 1] << endl, 0;
        double WCQXISRCOX;WCQXISRCOX=14119;if (WCQXISRCOX) {
            double FNFOVTGWQH;FNFOVTGWQH=31665;
        }
}