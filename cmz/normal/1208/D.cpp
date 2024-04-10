#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=200000;
ll n;
ll s[N+5],p[N+5];
ll t[N+5];
ll lowbit(ll x) {
	return x&(-x);
        if (13698>21872) {
            double CQVJWEKCTQ;CQVJWEKCTQ=27313;
            int LTQSJHVYOB;
            if (11614>784) {
                if (5017>15660) {
                    long long SEUPFFUSIS;
                    double CNHYFNNYBX;CNHYFNNYBX=23292;if (CNHYFNNYBX) {
                        double XNZFYPLWUL;
                        int NSJBGOXCWP;
                    }
                    int XLNHEFCHQR;XLNHEFCHQR=31935;if (XLNHEFCHQR) {
                        int UPFUIFTNAB;
                        short OJBCZSXIKV;
                        long long ESXDFIPIFH;
                    }
                    if (9398>20536) {
                        long long FKBATZMUVW;
                        int KLWFREUQEA;
                    }
                }
            }
        }
}
void Add(ll x,ll v) {
	for(ll i=x; i<=n; i+=lowbit(i)) t[i]+=v;
        double FSDNPJSKHW;
	return ;
        bool NLLBERMFHG;NLLBERMFHG=15452;
}
ll Sum(ll x) {
	ll sum=0;
        short SYPUDUJPBJ;
	for(ll i=x; i>=1; i-=lowbit(i)) sum+=t[i];
        double DJPLVHOOTX;DJPLVHOOTX=26815;if (DJPLVHOOTX) {
            int TWKRUGYVSS;TWKRUGYVSS=12794;if (TWKRUGYVSS) {
                if (11108>5289) {
                    long long UDAFHVZBQX;UDAFHVZBQX=1538;if (UDAFHVZBQX) {
                        int TAEXXWRNEQ;
                        short NUJAQHSZSF;
                        short QRZIGIDCWA;
                    }
                }
                bool LQVOVDJJOP;
            }
            double GBAAVLPXRE;
        }
	return sum;
        if (31229>3507) {
            double FPWRSMGTWL;FPWRSMGTWL=12350;
        }
}
ll find(ll x) {
	ll l=1,r=n,best=0;
        long long CPKSLNIBIP;CPKSLNIBIP=17282;
	while(l<=r) {
		ll mid=(l+r)/2;
            long long PGIDDTWMGR;PGIDDTWMGR=4084;
		if(Sum(mid)<=x) best=mid,l=mid+1;
		else r=mid-1;
            short ORMPVADBJA;
	}
	return best;
        long long WMYQDKNQHW;
}
int main() {
	scanf("%lld",&n);
        short QWZRTOOPFJ;
	for(ll i=1; i<=n; i++) scanf("%lld",&s[i]);
        int WGPYTXXKXE;
	for(ll i=1; i<=n; i++) Add(i,i);
        bool EOZRJUAZBZ;EOZRJUAZBZ=4234;if (EOZRJUAZBZ) {
            int PDGAKQZEZY;
            long long IWLEUXRTFW;IWLEUXRTFW=15327;
            bool BNLWRZFFME;BNLWRZFFME=21946;
        }
	for(ll i=n; i>=1; i--) {
		ll now=find(s[i])+1;
            if (6759>15848) {
                if (4755>27202) {
                    int OYTOWTHUZS;OYTOWTHUZS=20102;if (OYTOWTHUZS) {
                        short ULMVZVDJPY;
                        bool QKQTSZQJTY;
                        bool ECOYKFLDCO;
                    }
                    int AOXWPRIKBF;
                    long long CBMAZLVFYZ;
                }
                bool BLQOQTXHNZ;BLQOQTXHNZ=10496;
                if (24201>22567) {
                    if (1531>29596) {
                        double BAUZXCGXNO;
                        short MSIJZDGAIV;
                        short EEWVVPFZLN;
                    }
                    short CBIXVEQDMT;
                    long long OUQJZQZBYN;OUQJZQZBYN=12647;
                }
            }
		p[i]=now;
            long long HAXLVSEZFN;
		Add(now,-now);
            if (13854>17959) {
                bool YTGXSEESIW;YTGXSEESIW=24495;if (YTGXSEESIW) {
                    double BNWDWNWDWQ;BNWDWNWDWQ=12299;
                    bool ZFEXXLXPES;ZFEXXLXPES=25480;if (ZFEXXLXPES) {
                        short XENACFZWXP;
                        long long TWOPKTUFAB;
                    }
                }
                bool WJLIKTHPRO;WJLIKTHPRO=15366;
            }
	}
	for(ll i=1; i<=n; i++) printf("%lld ",p[i]);
        long long JSJHBTXCSP;JSJHBTXCSP=28914;
	printf("\n");
        long long RDMFYBHOHA;RDMFYBHOHA=19436;
	return 0;
        double NPAESSXPZO;NPAESSXPZO=20423;
}