// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2014 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

// 17.4.1.2 Headers

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
/*
                                                                                                                                                `
                                                                                                                                                `
                                                                                                                                                `
                                                                                                                                                `
                                                                                                                                                `
                                                                                                                                                `
                                                                                                                                                `
                                                                                                                                                `
                                                                         `!!!;'                                                                 `
                                                           '%$@########################&&%:.                                                    `
                                                       .%###################################%.                                                  `
                                                    .`|######################################%                                                  `
                                                 .!@###############################################$'                                           `
                                              .!@#########################@@@#########################&;.                                       `
                                             :@##################@@@&&@@@$!!%&@@@@@@@###################&'                                      `
                                          :&################@@@&$%%||||!!:'':;!!||%|!%&@@#################%`                                    `
                                         |###############@@&&$%|!;;::::':'''':::;;!!|%%%$&&@###############$`                                   `
                                      :&#############@&$%||||!;'````````````'''```'':::'':!|$@@###############;                                 `
                                    :@#############@$$%|!;;;;:'``````...```...`...`'':::''';|%$$$&############&'                                `
                                   |##############&$$$%||!!;:'`````..````....`...```''::::;!!||$&&@@###########&'                               `
                                 !##############@$%|!!!;::'''`````...``.....`````````'''::::;;::!|%$&############|                              `
                                :@##########@&%!:'`::;;:'``....```.......  .``....````````````'':;!|%$@############;                            `
                               ;##########@%;```...`'''`...  .....    ................   .`.    `:!!!!%%%&#########|                            `
                              ;##########&|:.`'`. ..`...   .......   .....  ..  .....   ...   .'':!!:.`''!@#########|.                          `
                              !##########|'`.;!`       .  ......          ..    .      ....  .::'`. .. .`'|@########@:                          `
                              ;##########%'`'%!    ..       .  .                ..    .```.   ';:`..``.`':|@########@:                          `
                              !##########$:;$&;                     . `|%;.  `;||;::`.``';;.  .;!: `;:`';|$#########@!.                         `
                              !##########@$&@|. ...... .`':!|;` !$|%%'!##$' `|####$:`:;:!&$:. '$&!';!!||%&############;                         `
                             `$#############&:  `!!'`:;;;||%@&!'!&&$;.|##%`.|#####%`'$@$&##%` .:||;;;;%@##############!                         `
                             :@#############|. .!&@|;%@@@@@&@@#@&@#@&@############@@#####@:   .`'%@%!!&###############!                         `
                             :@############@;   :&@!;$###@|%|!$@@######################@%`    .;|!;!|%@###############!                         `
                             :@############@:   `$#$%#@@##&@################@$$$&$%|!'       `%#@|;':|&###############!                         `
                              !##########@$%:    |####@&######$;.                          ..`'`      ;@##############!                         `
                              !##########!       ;#########|.                             `;`         ;###############!                         `
                              ;##########;       `%######;                           '$###&:          `%@############&'                         `
                               !########@:       .'.       .:;`                   .|%:                   !##########&'                          `
                               !########@:                                                               ;#########@:                           `
                                !######%.     !##&;.        .                  `%&!`             '&###&' !#########!                            `
                                |#######;.%###!                 `!&###@|;;%@###%.    ';;|&$:;;`     |#%. .%###%$###!                            `
                               !#######|  `%#&'    |##&$####&:     !##########;    `%#####%.!#|.   .%@:   ;###;`%##!                            `
                                !#$!$##!   :@#!        .|###$'.    ;##|.  :&#@;    .``::`          ;@|.   :@#@: `$#|                            `
                                :&&|&##;   :&#!                   :&##;    .%##!                   !&'    ;@##!  |#!                            `
                                 |@@##@;  .`%#!                  '$##;      ;##$`                 :@!    .|##@; :&!                             `
                                 !&|&##%:'.  :&!                :@#%.        .%##;               |&!.   `|@!   `$!                              `
                                 '$%%###&;.   '&&'            `%##&'           |##@&:    ...;&&&@;     .;&#|':;$&:                              `
                                 .|######&;        '$@@@@@@@@#|                                        :&######%`                               `
                                   !#####&:                                                           '$#####@:                                 `
                                   '$#####@:                                                          ;#####$`                                  `
                                     '&####%.                 ``                                     '$#####;                                   `
                                      !#####$'                |@:  .:%|;;;;!$#####@#|               '&###$:                                     `
                                       :&####&:               ;####################@:    ':`       `%###@:                                      `
                                         ;#####@%:.                                         `'';|@######$`                                      `
                                         `$######@|`                                        !#&||@#####$`                                       `
                                          :&######@%'.                        .`''''` .';!|%@#@$$@####&:                                        `
                                           |######@|'.   ;##$!!%@##########################@:   '$####;                                         `
                                           :&#####$;''.`%#########&'             `|@$:         .%###@;                                          `
                                            :@####@;          |#@##&$;         `|%'           .|####!                                           `
                                              !####@;                                .        |####!                                            `
                                               :@###@|`         .                 `|!.       |####%.                                            `
                                                .|####!          `;$@%|!!!!!%&&@#$;.        !#####|                                             `
                                                .%####&:              '%&@@@|`             '&#####|                                             `
                                                .%#####|.                                 :&######%`                                            `
                                       :|||;`    !#######;                              .%#####@@#####@$;.                                      `
                                   `$#############&%!%#####|.                         :@####%:..'!&######@;                                     `
                                  `$#############|`..'%#######!                      ;####&;.    .'%#######!                                    `
                                .|##############@!`    .'%#########%'.          '%#####%`           :@#######@%;:.                              `
                          ;%|;. !############%::;'        `!&############@&&@#######@%'               !###########&'                            `
                         !################$'   .:'         '|&######################$:.               :@#############@@@@@@;                    `
                      ';$##&;:&###########$`                  :|$@################%:.                 !#####################@;                  `
                   '%####@$!:.  `%#########!                    .:!%&@#######@%!;'.                   |##############%!$@####!                  `
                .|#######&;'. .    |#######%.                      .':;!!!!!!;`...                   .|############|. :$@@####%.                `
                !####&$&@#@!:'.       ;#####%`                  .`';;'... ..''``.                    !##########%`    ''':$######$`             `
                ;#####@$$;`%&:.         `%####;                   .:;;:'':;||!:`                    !#########!          :&#@@####!             `
          '%######@######!   !!            :$@$`                    ...`.'::`..                   '$######@!`         '|$$&!!@#######@!.        `
     '$#########@&$$@######@:    ;: . `'    ....                      ...``.                    `$######&'           '!;`'!@######&&########$'  `
  ;############@#@@@@@$|%@###$`  `!!.;' .     :!.                                             .%#####!.            .;::&####|`..`  ..;@########!'
  |########&|;'``..`:'    ..!##%:.    ;;      `.                                            .|###|`             `'|###@&$|`  ..   .`|&&@#######%:
  |###@#@@#&|:`.`';;:;!!!;:;''!$##&;'.  .'%; .;&###&|$!                                     '$; .|$:;|`   ...;&###$'    ....      :||%&########%:
  |#######@$;!%%:```           .!@###&|`   :|'!########@#!                                ;@! :@####%'. `|@###&:         ..`:::%$$&$$$&@##@@@##|:
  |########$;::'`         .`.     `%#####%!: .. !#####%` !#%.                        !; '%; !#############&:          `::`.```. .':.  :$@&&&###|:
  !####@%:::;;:::::` .........            '.  !#######%;;';; `%#&'             ;&: `;``$@!%########&&##&|::::'.             ':.     `!%@@######|:
  !#####%;;::.       ...... ....`..  ..  '::!|&########$';%`.'` .;%:        !#$';$%|&$!&##########$'        `';;;;!&##&%||||||%;`   .:|&###@###|:
  |#######|`...      `|$&&$$!`....           ;$:  :&#@:     `'''``.   .%########&'  .%#@&$%$#####$`     ....`:%&@@@@@@&&@@!`.      .`'%@#######|'
  |######@@$:       .`..`!@&$&&&&:                ;@#######@@#$%@######&$;    '%@##%!@###@&&@####%.     `!&@@@@@$:..`..``.``...     `|&####@@##!'
  ;###&|;::!&#&%%%%:         .'::::;|$&&$%|'..;%%&#######%;$########@&#####%`   '|@###;    '%####$;::::::`            '!|%%%%%%%%%&#$:'::.'%###|'
  `%###@|;|%$%$@#&|;::::`          '|%%%%%$%|%|;';$##@|'.   |######&'     .:|$%: :&@|'.     !####%.              `::;:!$@######&%%%%%!'  ':;&##|:
  '$##%:.    :&##@####@$;.  ..                    `$|     :; !#####|      '|%:  ``    ...   !####!          .  ..:&#@@@@##@&||$;         :&####|'
  !####&@@&;        ...`.'%@##@@#@@&!`            :&&!.       !###&'  :||:.`   !%'     ``:$######@@@&&@@@&@##$;``....             |@@@@########!'
  !#######@$||!:          ';!;;;!&###&|||||||||||%&##@!`.     !###&||%!!!:   .:;`        `;;%####$;:;;;;;;;;;;;::.         '||||||&#####%!;;$##!`
  `%#&:.`:!||||||%@#@%;::;;;'                     ;@@:    .. .%###|.   `:::'  .:!;'`':'`   `$####!             ':;;;;!%@@&%%%|;`        `;%&###|:
  .%##|..       '$##@@@@@@#&:...`..              `$#$'        !##%`   ..`.`:%@@! '%@$:''. .`|####|... .........`:%###@#@@@|`        ....`%#####|:
  !###@&!       .`.```':!&##@&&&&$:              '&#%.        !#&'     ````.    .```:%&&&&&@#####@!':|$&&$&&&&&&&&&@##|`````.       !@@@#######!'
  :&#########@$||||:            `::::;;;;;!!;;;:;$###$'  .'`  |#@|.  .:;;:.                `%####%:''':::::`               `!||&##$;;;:::.  ;##|:
  .%#@$%$%%%%%$@###$::::::'.           ...`;|!::!&##@$%|||!' .%##&%%$%'        `'.         :&####!                  .':::'::%@&$%%!` .!!':;$###%:
  :&#############@|.              .  '$##################&;..!@###@#######%'.             .!#####!          .              `$#####@|``;&|!&####|:
  |####&%'   .''''':|@###@$$$$$$%;.             |####%`      .|#@;.         .;$$$%$&$$$$$$&######$:..:|%$$$$$$$&&&&@######&;'''.    ;$&########|:
  |#######@%;;`    '!|!||$#######&|!!!;;;!!!;`.!#####@: .;|!!|&#$'   `:'':;;$######################################%!|!!!!!;.  .`;|&######@####%:
  |############$!''''..';$&&&&@########################$;'!;`:@#&:``'|$@######@@@@&&&&&&&@#######@&&&&&&&&&&&@@&&&&$|:.    .`''$########@&@####%:
  |###&%$&#################@%;'  ..      `|@############$: `%@###########$`  `%%:.     . :@######|         !#####################@$%&##########%:
  |#######################################@&&@######################@@&@#######################################################################%:
*/

#include <cstdio>
#include <cctype>
#include <cassert>
//namespace IO{
//	const int L = 1 << 15;
//	char ibuf[L|1],*iS=ibuf,*iT=ibuf;
//	char obuf[L|1],*oS=obuf,*oT=obuf+L;
//	char c,st[66];int tp=0,f;
//	inline char gc(){
//		if(iS==iT) iT=(iS=ibuf)+fread(ibuf,sizeof(char),L,stdin);
//		return (*iS++);
//	}
//	inline void flush() {
//		fwrite(obuf,sizeof(char),oS-obuf,stdout);
//		oS = obuf;
//	}
//	inline void pc(char c){*oS++=c;if(oS==oT) flush();}
//	#define gc getchar
//	#define pc putchar 
//	inline ll read_(){
//		ll x=0;f=1,c=gc();
//		for(;!isdigit(c);c=gc())if(c=='-')f=-1;
//		for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c&15);
//		return x*f;
//	}
//	void write_(ll x){
//		if(!x) pc('0');if(x<0) pc('-'),x=-x;
//		while(x) st[++tp]=x%10+'0',x/=10;
//		while(tp) pc(st[tp--]);
//	}
//	void writeln(ll x){write_(x);pc('\n');}
//	void wri(ll x){write_(x);pc(' ');}
//	struct IOflusher{~IOflusher(){flush();}}_ioflusher_;
//}
//using IO::read_;
//using IO::write_;
//using IO::writeln;
//using IO::wri;
namespace dts{
	#define ll long long
	#define ssss(p_1,p_2,p_3,p_4,p_5,p_6,p_7,p_8,p_9,n,...) n
	#define sss(a,s...) (ssss(0,##s,9,8,7,6,5,4,3,2,1,0)-1)
	#define shu_liang(a...) (sss(12,##a))
	#undef ll
	#define ll typename check<T>::type
	#include<stdarg.h>
	#define join(b) template<>class check<b>{public:typedef b type;}
	template<typename T>
	class check;
	join(int);
	join(unsigned);
	join(long);
	join(unsigned long);
	join(long long);
	join(unsigned long long);
	template<typename T,int xf>
	ll m_m(ll a,ll b) {
		if(xf==1)
		return a^((a^b)&-(a<b));
		if(xf==2)
		return b^((a^b)&-(a<b));
		if(xf==3)
		return a+b;
	}
	template<typename T,int xf>
	ll n_n(int n,ll a,...) {
		ll s=a;
		if(n<=1)return s;
	  va_list y; va_start(y,a);
	  for(int i=2;i<=n;i++)
	  s = m_m<ll,xf>(va_arg(y,ll),s);
	  va_end(y);
	  return s;
	}
	template<typename T>
	void read_one(T&x) {
	 x=0;T w=1;char c=getchar();
	 for(;c>'9'||c<'0';(c^'-')||(w=-w),c=getchar());
	 for(;c<='9'&&c>='0';(x=(x<<1)+(x<<(1<<1|1))+(c^48)),c=getchar());
	 x*=w;
	}
	template<typename T>
	void write_one(T x) {
	 if(x<0) {
	  putchar('-');
	  x=-x;
	 }
	 if(x<10) {
	  putchar(x^48);
	  return;
	 }
	 write_one(x/10);
	 putchar(x%10^48);
	}
	template<typename T>
	void read_some(int number,ll*a,...) {
		typedef T* X;
		read_one<ll>(*a);
		va_list s;va_start(s,a);
		for(int i=2;i<=number;i++) {read_one<ll>(*(va_arg(s,X)));}
		va_end(s);
	}
	template<typename T>
	void write_some(int number,ll a,...) {
		write_one<ll>(a);
		va_list s;va_start(s,a);
		for(int i=2;i<=number;i++) {putchar(' '),write_one<ll>((va_arg(s,T)));}
		putchar('\n');
		va_end(s);
	}
	#define read(a,x...) (read_some<__typeof__(*(a))>(shu_liang(a,##x),a,##x))
	#define write(a,x...) (write_some<__typeof__(a)>(shu_liang(a,##x),a,##x))
	#define max(a,x...) (n_n<__typeof__(a),1>(shu_liang(a,##x),a,##x))
	#define min(a,x...) (n_n<__typeof__(a),2>(shu_liang(a,##x),a,##x))
	#define sum(a,x...) (n_n<__typeof__(a),3>(shu_liang(a,##x),a,##x))
	#undef ll
	#define ll long long
	#undef pp
	#undef join
}
using namespace dts;
#define IO(ss) \
freopen(#ss".in","r",stdin);\
freopen(#ss".out","w",stdout)
#define debug
#ifdef debug
#define s__u__m 1
#else
#define s__u__m 0
#endif
#define she_(x) \
for(ll errer_##x=0;(error_##x)&&(puts("error_"#x":"),1);++error_##x)
#define she(x) she_(x)
ll jc[1000100];
int main(int wcr,char**AKIOI) {
	//IO(t3);
	ll n,m,s=0;
	read(&n,&m);
	jc[0]=1;
	for(ll i=1;i<=n;i++)jc[i]=jc[~-i]*i%m; 
	for(ll i=1;i<=n;i++)(s+=jc[i]*jc[n-i+1]%m*(n-i+1)%m)%=m;
	write(s);
	return 0;
}