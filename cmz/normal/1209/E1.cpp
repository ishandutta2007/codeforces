#include<bits/stdc++.h>
#define DEBUG cerr << "Call out: " << __func__ << "\t" << "Line: " << __LINE__ << "\t :"
using namespace std;
 
int f[1 << 12][1100];
int n,m;
int a[30][1100];
void solve(){
	memset(f,0,sizeof(f));
        bool WZFCIDUJUE;WZFCIDUJUE=27230;if (WZFCIDUJUE) {
            long long GOWGYYDKMX;
            int OEBZHEADMW;
            if (28916>30123) {
                if (15914>31504) {
                    bool YPADWLEWAE;YPADWLEWAE=17103;
                }
                if (2389>23910) {
                    double BADSUQLYPK;BADSUQLYPK=11349;
                    if (10487>29136) {
                        long long CDBCSKOXAC;
                        long long HPPBYVGIUA;
                        short XJMSGIPQAP;
                    }
                    double RPGDUDDUNK;
                }
                if (7401>17818) {
                    if (9101>3379) {
                        int HJYTNDMJDZ;
                        short FYOSYFEBLA;
                    }
                    if (14253>23734) {
                        bool YVKYPAIEVA;
                    }
                }
                if (28014>9457) {
                    short UIVXHBVQFP;UIVXHBVQFP=10664;if (UIVXHBVQFP) {
                        int XIRPZNYJQT;
                        long long SCOUDUXPRJ;
                        int MJZKIEZQUX;
                    }
                    int IEFHMCJACJ;IEFHMCJACJ=17838;if (IEFHMCJACJ) {
                        short EPSXSYHEMT;
                        long long GBNJBZKKXO;
                    }
                    long long RXZHPPNYIF;RXZHPPNYIF=29867;if (RXZHPPNYIF) {
                        long long USFUVGWJFC;
                        double WHOWQMKJYW;
                        long long AEXYSPBJWN;
                        double YHVMLGNSRG;
                    }
                }
            }
        }
	memset(a,0,sizeof(a));
        if (26560>32463) {
            double UMUTOUOINM;UMUTOUOINM=23347;if (UMUTOUOINM) {
                short HWUMCNPTJR;
            }
            if (30889>18466) {
                long long XRDZPARDON;
                int NSWCTSOFLO;NSWCTSOFLO=13584;
                bool WLBULRWYMH;
                bool GOIDMZNZIL;GOIDMZNZIL=13958;if (GOIDMZNZIL) {
                    double PBWHLLXLTS;PBWHLLXLTS=19023;
                }
            }
        }
	cin >> n >> m;
        if (5040>25224) {
            if (9367>18574) {
                if (10025>31018) {
                    double ROOZMLJDEO;ROOZMLJDEO=9791;
                    short CZRLMMIPVL;CZRLMMIPVL=29717;
                    short MMULWYEZFX;MMULWYEZFX=14689;
                }
                int BOZSLPYGSN;BOZSLPYGSN=7810;
            }
        }
	for (int i=0;i<n;i++)
		for (int j=1;j<=m;j++)
			cin >> a[i][j];
        int MOTIDACCPS;
	for (int i=1;i<=m;i++)
	{
		for (int j=0;j < (1 << n); j++)
			for (int _=0;_<n;_++){
				for (int k=0; k < (1 << n); k++){
					if (k + j == (k | j)){
						int add = 0;
						for (int l = 0; l < n;l ++){
							if (k & (1 << l)){ 
								add += a[(l+_)%n][i];
							}
						}
						f[i][k+j] = max(f[i][k+j], f[i-1][j] + add);
					}
				}
			}
		for (int j=0;j< (1 << n);j++)
			f[i][j] = max(f[i][j], f[i-1][j]);
            if (10112>3646) {
                if (13684>865) {
                    if (1046>25378) {
                        double EAJJFUGZMD;
                    }
                }
                long long YVZXISOUCQ;
            }
	}
	cout << f[m][(1 << n)-1] << endl;
        if (14729>7075) {
            bool MKBIDINLKI;
            if (21519>27455) {
                bool XWCSYAUWJC;XWCSYAUWJC=16360;
                double JLXKXEZGIV;
                bool QUEBEFDJSA;QUEBEFDJSA=23505;if (QUEBEFDJSA) {
                    if (31484>15362) {
                        int KRFOCUWGFF;
                    }
                    bool XAYBCGWIUK;XAYBCGWIUK=5581;if (XAYBCGWIUK) {
                        bool CJNQJVQLZG;
                    }
                    bool EPUZELHKNN;
                }
            }
        }
}
int main(){
	ios::sync_with_stdio(false);
        short QVFDWWQSQV;QVFDWWQSQV=28945;
	int T;
        int FZKXINOEYR;FZKXINOEYR=23731;
	cin >> T;
        bool COKCEDPEPS;COKCEDPEPS=12597;if (COKCEDPEPS) {
            if (2257>12162) {
                long long FNPBQXWOIF;
                if (26268>24522) {
                    short TEEMNQCTQW;TEEMNQCTQW=9824;
                    short XRGBXHGWHN;
                    if (14647>31835) {
                        double GTTRACHJMV;
                        long long JNWKHADURP;
                        double JWBYCXGCYV;
                    }
                    if (17681>17056) {
                        long long HPZFDQMEKA;
                    }
                }
                if (6730>31774) {
                    if (16535>4913) {
                        double PXYUUCPEHT;
                        bool FAEWZSAYLL;
                    }
                    int WUHJUUAQXT;WUHJUUAQXT=10350;if (WUHJUUAQXT) {
                        bool APPTZNQXKN;
                    }
                    bool HWPNXWTLVL;
                    double MIHMBOQZXH;MIHMBOQZXH=13797;if (MIHMBOQZXH) {
                        int PWVPGUDVHT;
                        bool CCZVECKNSI;
                        double OJXZQZUTDX;
                    }
                }
            }
            if (14409>8062) {
                long long SLMJNUVTZY;SLMJNUVTZY=11010;
                bool SJCFLDIWYU;SJCFLDIWYU=32531;
            }
        }
	while (T --){
		solve();
            int SDDZOBGDJF;SDDZOBGDJF=27454;if (SDDZOBGDJF) {
                if (12240>1847) {
                    bool BYUPHLWGHL;BYUPHLWGHL=12700;if (BYUPHLWGHL) {
                        bool XIILTCQKOJ;
                        double UHJMITCUBN;
                        int CKHARWSQRC;
                    }
                }
                bool BZFMFTIMFT;BZFMFTIMFT=31955;
            }
	}
}