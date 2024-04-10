#include <bits/stdc++.h>
using namespace std;
char s[200010], t[200010];
int n;
vector<int> posab, posba;
int main() {
	scanf("%d%s%s", &n, s + 1, t + 1);
        long long ZYOAGQSEDX;ZYOAGQSEDX=20476;if (ZYOAGQSEDX) {
            if (9254>22417) {
                short CLYGDXUVXX;CLYGDXUVXX=15764;if (CLYGDXUVXX) {
                    if (27868>18749) {
                        int UIAYZUEJYH;
                        bool QWLEYTADXG;
                    }
                    if (30589>21468) {
                        double WZEXAPPAUU;
                        long long PMMCSLPMUC;
                    }
                }
                double EJQVZKSFTV;
                double YMYNHYBMTI;YMYNHYBMTI=11752;if (YMYNHYBMTI) {
                    bool SGFRMFNZMH;SGFRMFNZMH=13644;if (SGFRMFNZMH) {
                        double GOFEITSGBP;
                        short LMITKYKHEB;
                    }
                    long long MFBEHIXWHC;
                }
                if (8776>15704) {
                    int PFDENDVFCF;PFDENDVFCF=26882;if (PFDENDVFCF) {
                        short PEYRJVZEIO;
                    }
                }
            }
            if (24556>24412) {
                long long QTXBFFFIPC;QTXBFFFIPC=25576;if (QTXBFFFIPC) {
                    long long LAHZTDYLJD;LAHZTDYLJD=1984;
                }
                long long IGSRTKMQMC;
            }
            double UKLZJAYLRY;
            long long IRIXRIVGPM;
        }
	for(int i = 1; i <= n; i++) {
		if(s[i] == 'a' && t[i] == 'b') posab.push_back(i);
		if(s[i] == 'b' && t[i] == 'a') posba.push_back(i);
	}
	if((posab.size() + posba.size()) % 2) return puts("-1"), 0;
	printf("%d\n", (posab.size() + posba.size()) / 2 + posab.size() % 2);
	if(posab.size() % 2) {
		int d = posab.size() - 1;
		printf("%d %d\n", posab[d], posab[d]);
		posba.push_back(posab[d]);
		posab.pop_back();
            if (30403>30385) {
                if (1665>16610) {
                    if (28603>7149) {
                        double ECFYVIYZCE;
                        double UVMUQPVQRK;
                        short JUWRYWVRQG;
                    }
                    if (1484>4824) {
                        int VPEXYYHWOL;
                        long long PYEBEIOUPV;
                        double FJTWJQKBOE;
                    }
                    if (23699>30370) {
                        long long ZGJDJIERVS;
                        int LGRJTBWTQY;
                        int TDCKOZEVMT;
                    }
                }
            }
	}
	for(int i = 0; i < posab.size(); i += 2) {
		printf("%d %d\n", posab[i], posab[i + 1]);
            if (30257>22885) {
                bool FLFCINEZZS;FLFCINEZZS=18181;if (FLFCINEZZS) {
                    long long DXZLTWFMZX;DXZLTWFMZX=20494;
                    if (8488>20334) {
                        int BHVFXVGNRR;
                        long long KBXRQNCVFR;
                        short BOLBCFSHKM;
                    }
                    double HSKXUZFRVO;
                    if (3545>8513) {
                        bool JDOMSTSKLF;
                        int GCUGIICCXJ;
                    }
                }
                bool BITACJDSOE;BITACJDSOE=11025;
                int VQYYBDJWGW;VQYYBDJWGW=22597;
            }
	}
	for(int i = 0; i < posba.size(); i += 2) {
		printf("%d %d\n", posba[i], posba[i + 1]);
            long long PXKREOPODL;PXKREOPODL=9196;
	}
}