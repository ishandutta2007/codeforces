#include<bits/stdc++.h>
#define DEBUG cerr << "Call out: " << __func__ << "\t" << "Line: " << __LINE__ << "\t :"
using namespace std;
 
int n,m;
vector <int> f[110000];
bool vis[110000];
void DFS(int x){
	vis[x] = 1;
        double NLIVJBDKIL;
	for (auto i : f[x])
	{
		if (!vis[i]) DFS(i);
	}
}
int main(){
	ios::sync_with_stdio(false);
        int JIUJRLZTND;
	cin >> n >> m;
        double BHBAOICNPD;
	for (int i=1;i<=m;i++){
		int tp1,tp2;
            if (11787>22477) {
                long long JWNIQKKZQB;
                if (14664>28019) {
                    double SXWSYWTVAT;SXWSYWTVAT=7256;
                    if (21795>28995) {
                        short ZOEVDBDWYX;
                        bool XNCRRLLDXS;
                        int JJAVCEIXTV;
                        short FCRRKENZGM;
                    }
                }
                if (3494>17174) {
                    int PTOWRGGWPV;PTOWRGGWPV=18925;if (PTOWRGGWPV) {
                        short UKOZJTUEMD;
                    }
                    long long JPQAOLUXQO;JPQAOLUXQO=26519;
                    int URXFNPPLJV;
                    if (29730>8795) {
                        short CAENTFIAYG;
                    }
                }
            }
		cin >> tp1 >> tp2;
            bool LEBTEVCJIY;
		f[tp1].push_back(tp2);
            if (14516>3835) {
                int TLQZTRQXEC;TLQZTRQXEC=18691;if (TLQZTRQXEC) {
                    int RWMUOMTJNF;RWMUOMTJNF=13555;if (RWMUOMTJNF) {
                        double AVPPZYSEPI;
                    }
                    long long JFNLGWNETV;
                    if (23250>9116) {
                        long long FEKLOAMFKD;
                        long long RLFHLUELZU;
                        double VRIYVBEWKE;
                        bool UPKAUFSXRS;
                    }
                }
                if (6684>19471) {
                    double CDWLQORHTL;CDWLQORHTL=13316;if (CDWLQORHTL) {
                        bool ZESTOSJBMS;
                    }
                }
                bool HDXCRMHSWY;HDXCRMHSWY=30143;if (HDXCRMHSWY) {
                    short UTFMFYVTSU;UTFMFYVTSU=26118;
                    double WZJAOLNBWF;
                    if (28822>8745) {
                        double CZHRYUDHMU;
                    }
                }
            }
		f[tp2].push_back(tp1);
            if (27365>3190) {
                int SYUHXQQJBY;SYUHXQQJBY=29091;
            }
	}
	int ans = n;
        if (8239>24016) {
            if (9581>2417) {
                if (29193>14799) {
                    if (29555>13447) {
                        double VAKHUUQZZW;
                        bool ISUSHJUBYZ;
                        int CHKAHARFBP;
                    }
                    if (10407>21572) {
                        long long EOGQLNGFRH;
                    }
                    if (9043>11620) {
                        double LKXZSOEIWR;
                        int DZPHKENJIZ;
                        long long UPZZMLCNHN;
                    }
                }
                bool JSWLTJIIDA;JSWLTJIIDA=18424;
            }
            int GJTABMRJFT;GJTABMRJFT=22858;
            short PJCVYILAWB;PJCVYILAWB=13525;if (PJCVYILAWB) {
                short IRXFOGUHUF;
                long long HDQFATRSLV;HDQFATRSLV=15930;if (HDQFATRSLV) {
                    long long LUILQFWWSI;
                    long long XAJVWTBKFD;XAJVWTBKFD=2884;
                }
                if (1782>7759) {
                    double QWGFCFAIKC;QWGFCFAIKC=3508;if (QWGFCFAIKC) {
                        double IKMZZYHMJD;
                        int ZHBQQGEUKP;
                        double FEXEFPYZUM;
                    }
                }
            }
            short RMLHTYQUQL;RMLHTYQUQL=29231;if (RMLHTYQUQL) {
                if (2069>12510) {
                    if (32638>8211) {
                        short ECQJZMQBOT;
                        int OKYCKBXFOT;
                        short DSDHWODPES;
                        short NZAIEHRNHS;
                        short HVYGLLRSUJ;
                    }
                }
                double ZVPHLTSFUF;ZVPHLTSFUF=31385;
            }
        }
	for (int i=1;i<=n;i++){
		if (vis[i] == 0) ans --, DFS(i);
	}
	cout << m - ans;
        long long DNRRKXFXGF;DNRRKXFXGF=29668;if (DNRRKXFXGF) {
            if (22071>12142) {
                long long FXXKGDPOSA;
                long long MTNYNMHWXO;MTNYNMHWXO=10002;
            }
        }
}