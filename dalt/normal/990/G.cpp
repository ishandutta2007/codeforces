#if (defined Contest45G) or (defined ONLINE_JUDGE)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<complex>
#include<string.h>
#include<limits.h>


#define INF 100000000
#define SWAP(a, b, type) {type _tmp = a; a = b; b = _tmp;}
#define PI 3.14159265358979323846
#ifndef __int64
#define __int64 long long
#endif
#define ll __int64
#define ull unsigned ll
#define ld long double
#define uint unsigned int
#ifdef ONLINE_JUDGE
#define ASSERT(x) ;
#else
#define ASSERT(x) if(!(x)) exit(-1);
#endif
#ifndef LLONG_MAX 
#define LLONG_MAX 0x7fffffffffffffffLL
#endif
#ifndef LLONG_MIN
#define LLONG_MIN (-LLONG_MAX - 1)
#endif

namespace dalt {
	namespace mathematic {
		const int floorLog2CacheSize = 1;
		int floorLog2Cache[floorLog2CacheSize];
		void MATHEMATIC_INIT() {
			int log = 1;
			for (int i = 1; i < floorLog2CacheSize; i++)
			{
				if ((1 << log) <= i)
				{
					log++;
				}
				floorLog2Cache[i] = log - 1;
			}
		}

		inline int modular(int x, int m) {
			return (x % m + m) % m;
		}

		inline int intRound(double x) {
			return int(x + 0.5);
		}
		inline int intRound(float x) {
			return int(x + 0.5);
		}
		int numberOfLeadingZero(unsigned int i)
		{
			// HD, Figure 5-6
			if (i == 0)
				return 32;
			int n = 1;
			if (i >> 16 == 0) { n += 16; i <<= 16; }
			if (i >> 24 == 0) { n += 8; i <<= 8; }
			if (i >> 28 == 0) { n += 4; i <<= 4; }
			if (i >> 30 == 0) { n += 2; i <<= 2; }
			n -= i >> 31;
			return n;
		}
		inline int floorLog2(int x)
		{
			if (floorLog2CacheSize > x)
			{
				return floorLog2Cache[x];
			}
			return 31 - numberOfLeadingZero(x);
		}
		inline int ceilLog2(int x)
		{
			if (floorLog2CacheSize > x)
			{
				if ((1 << floorLog2Cache[x]) == x)
				{
					return floorLog2Cache[x];
				}
				else
				{
					return floorLog2Cache[x] + 1;
				}
			}
			return 32 - numberOfLeadingZero(x - 1);
		}

		template<class T> inline T &min(T&a, T&b) {
			return a <= b ? a : b;
		}

		template<class T> inline const T & min(const T & a, const T & b) {
			return a <= b ? a : b;
		}

		template<class T> inline T &max(T&a, T&b) {
			return a >= b ? a : b;
		}

		template<class T> inline const T &max(const T &a, const T &b) {
			return a >= b ? a : b;
		}

		ull pow(uint x, int n, int mod) {
			int bit = floorLog2(n);
			ull product = 1;
			for (; bit >= 0; bit--) {
				product = product * product % mod;
				if (((1 << bit) & n) != 0) {
					product = product * x % mod;
				}
			}

			return product;
		}
		inline ull gcd0(ull a, ull b)
		{
			return b == 0 ? a : gcd0(b, a % b);
		}
		inline ull gcd(ull a, ull b)
		{
			return a >= b ? gcd0(a, b) : gcd0(b, a);
		}


		inline uint gcd0(uint a, uint b)
		{
			return b == 0 ? a : gcd0(b, a % b);
		}
		inline uint gcd(uint a, uint b)
		{
			return a >= b ? gcd0(a, b) : gcd0(b, a);
		}



		/**
		* Put all primes less or equal to limit into primes after offset
		*/
		int eulerSieve(int limit, int* const primes, int offset) {
			bool *isComp = new bool[limit + 1];
			memset(isComp, 0, sizeof(bool) * (limit + 1));
			int wpos = offset;
			for (int i = 2; i <= limit; i++) {
				if (!isComp[i]) {
					primes[wpos++] = i;
				}
				for (int j = offset, until = limit / i; j < wpos && primes[j] <= until; j++) {
					int pi = primes[j] * i;
					isComp[pi] = true;
					if (i % primes[j] == 0) {
						break;
					}
				}
			}
			//delete[] isComp;
			return wpos - offset;
		}
	}

	namespace io {
		const int BUF_SIZE = 1 << 13;
		char w_buf[BUF_SIZE];
		char r_buf[BUF_SIZE];
		int r_pos;
		int w_pos;
		int r_total;
		int w_total;
		int r_next;

		const char *MIN_INT_STR = "-2147483648";
		const char *MIN_LONG_STR = "-9223372036854775808";



		int read() {
			if (r_pos >= r_total)
			{
				r_pos = 0;
				r_total = fread(r_buf, sizeof(char), BUF_SIZE, stdin);
				if (r_total == 0)
				{
					return -1;
				}
			}
			return r_buf[r_pos++];
		}

		inline void ignoreBlank() {
			while (r_next >= 0 && r_next <= 32)
			{
				r_next = read();
			}
		}

		uint readUnsignedInt() {
			ignoreBlank();
			uint sum = 0;
			while (r_next >= '0' && r_next <= '9')
			{
				sum = sum * 10 + r_next - '0';
				r_next = read();
			}
			return sum;
		}

		int readNegativeInt() {
			ignoreBlank();
			int sum = 0;
			while (r_next >= '0' && r_next <= '9')
			{
				sum = sum * 10 - r_next + '0';
				r_next = read();
			}
			return sum;
		}

		int readInt() {
			ignoreBlank();

			bool sign = true;
			if (r_next == '+' || r_next == '-')
			{
				sign = r_next == '+';
				r_next = read();
			}

			return sign ? readUnsignedInt() : readNegativeInt();
		}

		uint readUnsignedLong() {
			ignoreBlank();
			ull sum = 0;
			while (r_next >= '0' && r_next <= '9')
			{
				sum = sum * 10 + r_next - '0';
				r_next = read();
			}
			return sum;
		}

		ll readNegativeLong() {
			ignoreBlank();
			ll sum = 0;
			while (r_next >= '0' && r_next <= '9')
			{
				sum = sum * 10 - r_next + '0';
				r_next = read();
			}
			return sum;
		}

		ll readLong() {
			ignoreBlank();

			bool sign = true;
			if (r_next == '+' || r_next == '-')
			{
				sign = r_next == '+';
				r_next = read();
			}

			return sign ? readUnsignedLong() : readNegativeLong();
		}

		int readString(char *buf, int limit) {
			ignoreBlank();

			char *end = buf + limit;
			char *iter = buf;
			while (iter != end && r_next > 32)
			{
				*(iter++) = r_next;
				r_next = read();
			}
			return iter - buf;
		}
		inline void flush() {
			fwrite(w_buf, sizeof(char), w_pos, stdout);
			w_pos = 0;
		}
		inline void write(char c)
		{
			if (w_pos == BUF_SIZE) {
				flush();
			}
			w_buf[w_pos++] = c;
		}
		inline void writeDouble(char *format, double d) {
			if (BUF_SIZE - w_pos < 100)
			{
				flush();
			}
			w_pos += sprintf(w_buf, format, d);
		}
		inline void writeString(const char *data, int len)
		{
			for (int i = 0; i < len; i++)
			{
				write(data[i]);
			}
		}
		inline void writeString(const char *data)
		{
			for (; *data; data++)
			{
				write(*data);
			}
		}

		inline void writeUnsignedLong(ull i) {
			if (i >= 10)
			{
				writeUnsignedLong(i / 10);
			}
			write(i % 10 + '0');
		}
		void writeLong(ll i) {
			if (i < 0)
			{
				if (i == LLONG_MIN)
				{
					writeString(MIN_INT_STR);
				}
				else {
					write('-');
					writeUnsignedLong(-i);
				}
			}
			else {
				writeUnsignedLong(i);
			}
		}

		inline void writeUnsignedInt(uint i) {
			if (i >= 10)
			{
				writeUnsignedInt(i / 10);
			}
			write(i % 10 + '0');
		}
		void writeInt(int i) {
			if (i < 0)
			{
				if (i == INT_MIN)
				{
					writeString(MIN_INT_STR);
				}
				else {
					write('-');
					writeUnsignedInt(-i);
				}
			}
			else {
				writeUnsignedInt(i);
			}
		}

		bool hasMore() {
			ignoreBlank();
			return r_next != -1;
		}
	}

	namespace random {
		const int GEN_BIT = 15;
		int seed;
		inline int rand()
		{
			seed = seed * 1103515245 + 12345;
			return (unsigned int)(seed / 65536) % 32768;
		}
		inline void RANDOM_INIT(int s) {
			seed = s;
		}
		inline void RANDOM_INIT() {
			RANDOM_INIT(time(0));
		}
		ull genBits(int bitNum)
		{
			int bit = 0;
			ull val = 0;
			while (bit < bitNum)
			{
				bit += GEN_BIT;
				val = (val << GEN_BIT) | rand();
			}
			if (bitNum == 64)
			{
				return val;
			}
			else
			{
				return val & (((ull)1 << bitNum) - 1);
			}
		}
		inline uint genUInt() {
			return genBits(32);
		}
		inline double genDoubleBits(int bitNum) {
			return (double)genBits(bitNum) / ((ull)1 << bitNum);
		}
		inline double genDouble() {
			return genDoubleBits(52);
		}
		inline int genIntRange(int min, int max) {
			return (int)(genDoubleBits(30) * (max - min + 1)) + min;
		}
		template<class E> void randomize(E *data, int len) {
			for (int i = len - 1; i > 0; i--)
			{
				int j = genIntRange(0, i);
				SWAP(data[i], data[j], E);
			}
		}
	}

	namespace segment {
		typedef struct _Segment *Segment;
		struct _Segment {
			Segment left;
			Segment right;
		};
		void pushUp(Segment s)
		{}
		void pushDown(Segment s) {
		}
		Segment newSegment() {
			Segment segment = (Segment)calloc(1, sizeof(struct _Segment));
			return segment;
		}
		Segment cloneSegment(Segment s) {
			Segment segment = newSegment();
			*segment = *s;
			return segment;
		}
		void query(Segment s, int f, int t, int l, int r) {
			if (f > r || t < l)
			{
				return;
			}
			if (f <= l && t >= r)
			{
				return;
			}

			int m = (l + r) >> 1;

			pushDown(s);
			query(s->left, f, t, l, m);
			query(s->right, f, t, m + 1, r);
		}
		void update(Segment s, int f, int t, int l, int r) {
			if (f > r || t < l)
			{
				return;
			}
			if (f <= l && t >= r)
			{
				return;
			}

			int m = (l + r) >> 1;

			pushDown(s);
			update(s->left, f, t, l, m);
			update(s->right, f, t, m + 1, r);
			pushUp(s);
		}
		Segment updatePersistently(Segment s, int f, int t, int l, int r) {
			if (f > r || t < l)
			{
				return s;
			}
			s = cloneSegment(s);
			if (f <= l && t >= r)
			{
				return s;
			}

			int m = (l + r) >> 1;

			pushDown(s);
			s->left = updatePersistently(s->left, f, t, l, m);
			s->right = updatePersistently(s->right, f, t, m + 1, r);
			pushUp(s);

			return s;
		}
	}

	namespace fft {
		using std::complex;
		complex<double> g_wn1_cache[32];
		int g_revBits[1 << 18];

		void FFT_INIT() {
			for (uint i = 0; i < 32; i++)
			{
				double angle = 2 * PI / ((uint)1 << i);
				g_wn1_cache[i] = complex<double>(cos(angle), sin(angle));
			}
		}

		void revBits(int log) {
			int n = 1 << log;
			int log_1 = log - 1;
			for (int i = 1; i < n; i++)
			{
				g_revBits[i] = (g_revBits[i >> 1] >> 1) | ((i & 1) << log_1);
			}
		}

		void dft(complex<double> *p, int log) {
			int n = 1 << log;
			for (int i = 0; i < n; i++)
			{
				if (g_revBits[i] < i)
				{
					continue;
				}
				SWAP(p[i], p[g_revBits[i]], complex<double>);
			}

			for (int d = 0; d < log; d++) {
				int s = 1 << d;
				int s2 = s + s;
				complex<double> &w1 = g_wn1_cache[d + 1];
				for (int i = 0; i < n; i += s2)
				{
					complex<double> w = 1;
					for (int j = 0; j < s; j++)
					{
						int a = i + j;
						int b = a + s;
						complex<double> t = w * p[b];
						complex<double> q = p[a];
						p[b] = q - t;
						p[a] = q + t;
						w *= w1;
					}
				}
			}
		}

		void dot_mul(complex<double> *a, complex<double> *b, complex<double> *c, int log)
		{
			int n = 1 << log;
			for (int i = 0; i < n; i++)
			{
				c[i] = a[i] * b[i];
			}
		}

		void idft(complex<double> *p, int log) {
			int n = 1 << log;
			dft(p, log);

			double dn = n;
			p[0] /= dn;
			p[n / 2] /= dn;
			for (int i = 1, until = n / 2; i < until; i++)
			{
				SWAP(p[i], p[n - i], complex<double>);
				p[i] /= dn;
				p[n - i] /= dn;
			}
		}
	}

	namespace hash {
		const int PRIME = 1000000007;
		typedef struct _Hash *Hash;
		struct _Hash {
			int *h;
			int *inv;
		};
		Hash newHash(char *data, int len, int x)
		{
			ASSERT(len > 0);

			Hash hash = (Hash)calloc(1, sizeof(struct _Hash));

			int *h = (int*)calloc(len, sizeof(int));
			int *inv = (int*)calloc(len, sizeof(int));

			inv[0] = 1;
			ull y = mathematic::pow(x, PRIME - 2, PRIME);
			for (int i = 1; i < len; i++)
			{
				inv[i] = inv[i - 1] * y % PRIME;
			}

			ull xi = 1;
			h[0] = data[0];
			for (int i = 1; i < len; i++)
			{
				xi = xi * x % PRIME;
				h[i] = (xi * data[i] + h[i - 1]) % PRIME;
			}

			hash->h = h;
			hash->inv = inv;

			return hash;
		}
		int doHash(Hash hash, int min, int max) {
			if (min == 0)
			{
				return hash->h[max];
			}
			return (mathematic::modular(hash->h[max] - hash->h[min - 1], PRIME) * (ull)hash->inv[min] % PRIME);
		}
	}

	namespace st {
		typedef struct _ST *ST;
		using mathematic::floorLog2;
		struct _ST {
			void ***min;
			int(*cmp)(void*, void*);
		};

		void* minItem(void *a, void *b, int(*cmp)(void*, void*))
		{
			return cmp(a, b) <= 0 ? a : b;
		}

		ST newST(void **data, int len, int(*cmp)(void*, void*)) {
			int log = floorLog2(len) + 1;

			void ***min = (void***)calloc(log, sizeof(void**));
			for (int i = 0; i < log; i++)
			{
				min[i] = (void**)calloc(len, sizeof(void*));
			}

			memcpy(min[0], data, sizeof(void*)*len);
			for (int i = 1; i < log; i++)
			{
				int s = (1 << i);
				int h = s >> 1;
				for (int j = 0; j < len; j++)
				{
					if (j + h >= len)
					{
						min[i][j] = min[i - 1][j];
					}
					else
					{
						min[i][j] = minItem(min[i - 1][j], min[i - 1][j + s - h], cmp);
					}
				}
			}

			ST st = (ST)calloc(1, sizeof(struct _ST));
			st->cmp = cmp;
			st->min = min;

			return st;
		}

		void *query(ST st, int min, int max)
		{
			int len = max - min + 1;
			int log = floorLog2(len);
			return minItem(st->min[log][min], st->min[log][max + 1 - (1 << log)], st->cmp);
		}
	}

	namespace hashmap {
		typedef struct _HashMapEntry *HashMapEntry;
		typedef struct _HashMap *HashMap;
		typedef struct _HashMapIterator *HashMapIterator;
		struct  _HashMapEntry {
			HashMapEntry next;
			HashMapEntry last;
			void *val;
			void *key;
			int hash;
		} NILEntry;
		struct  _HashMap {
			HashMapEntry *entries;
			int capacity;
			int size;
			double factor;
			int shrink;
			int mask;
			bool(*equal)(const void *a, const void *b);
			int(*hash)(const void*ptr);
		};
		struct  _HashMapIterator {
			HashMap map;
			HashMapEntry entry;
			int index;
		};
		HashMapEntry newHashMapEntry()
		{
			HashMapEntry entry = (HashMapEntry)calloc(1, sizeof(struct  _HashMapEntry));
			return entry;
		}
		HashMapEntry newHashMapEntry(void *key, void *value, int hash)
		{
			HashMapEntry entry = newHashMapEntry();
			entry->hash = hash;
			entry->key = key;
			entry->val = value;
			return entry;
		}
		HashMap newHashMap(int capacity, double factor, int(*hash)(const void*), bool(*equal)(const void*, const void*))
		{
			capacity = capacity / factor;
			int log = mathematic::ceilLog2(capacity);
			capacity = 1 << log;

			HashMapEntry *entries = (HashMapEntry *)calloc(capacity, sizeof(HashMapEntry));
			for (int i = 0; i < capacity; i++)
			{
				entries[i] = &NILEntry;
			}

			HashMap map = (HashMap)calloc(1, sizeof(struct _HashMap));
			map->capacity = capacity;
			map->entries = entries;
			map->factor = factor;
			map->shrink = capacity * factor;
			map->size = 0;
			map->hash = hash;
			map->equal = equal;
			map->mask = (1 << log) - 1;

			return map;
		}
		HashMapEntry checkList(HashMapEntry entry, void *key, int hash, bool(*equal)(const void*, const void*))
		{
			while (entry != &NILEntry)
			{
				if (entry->key == key || (entry->hash == hash && equal(entry->key, key)))
				{
					return entry;
				}
				entry = entry->next;
			}
			return &NILEntry;
		}
		inline int getHash(HashMap map, void*key)
		{
			uint h = map->hash(key);
			return h ^ (h >> 16);
		}
		inline int getIndex(HashMap map, int hash) {
			return map->mask & hash;
		}
		void add(HashMap map, void *key, void *value)
		{
			int hash = getHash(map, key);
			int index = getIndex(map, hash);
			HashMapEntry exist = checkList(map->entries[index], key, hash, map->equal);
			if (exist != &NILEntry)
			{
				exist->val = value;
				return;
			}

			HashMapEntry newEntry = newHashMapEntry(key, value, hash);
			HashMapEntry top = map->entries[index];
			top->last = newEntry;
			newEntry->next = top;
			map->entries[index] = newEntry;

			map->size++;
		}
		void *find(HashMap map, void *key)
		{
			int hash = getHash(map, key);
			int index = getIndex(map, hash);
			HashMapEntry exist = checkList(map->entries[index], key, hash, map->equal);
			return exist == &NILEntry ? NULL : exist->val;
		}
		bool contain(HashMap map, void *key)
		{
			int hash = getHash(map, key);
			int index = getIndex(map, hash);
			HashMapEntry exist = checkList(map->entries[index], key, hash, map->equal);
			return exist != &NILEntry;
		}
		void remove(HashMap map, void *key)
		{
			int hash = getHash(map, key);
			int index = getIndex(map, hash);
			HashMapEntry exist = checkList(map->entries[index], key, hash, map->equal);
			if (exist == &NILEntry)
			{
				return;
			}
			exist->next->last = exist->last;
			if (exist->last)
			{
				exist->last->next = exist->next;
			}
			else
			{
				map->entries[index] = exist->next;
			}
			exist->next = NULL;
			exist->last = NULL;

			map->size--;
		}
		HashMapIterator newIterator(HashMap map)
		{
			HashMapIterator iterator = (HashMapIterator)calloc(1, sizeof(struct _HashMapIterator));
			iterator->entry = &NILEntry;
			iterator->index = -1;
			iterator->map = map;
			return iterator;
		}
		bool hasMore(HashMapIterator iterator) {
			while (iterator->entry == &NILEntry && iterator->index + 1 < iterator->map->capacity)
			{
				iterator->entry = iterator->map->entries[++iterator->index];
			}
			return iterator->entry != &NILEntry;
		}
		HashMapEntry nextEntry(HashMapIterator iterator) {
			HashMapEntry entry = iterator->entry;
			iterator->entry = entry->next;
			return entry;
		}
	}

	namespace sort {
		template<class T> void selectSort(T*ptr, int len, int(*cmp)(const void*, const void*))
		{
			for (int i = 0; i < len; i++)
			{
				int m = i;
				for (int j = i + 1; j < len; j++)
				{
					if (cmp(ptr + m, ptr + j) > 0) {
						m = j;
					}
				}
				if (m != i)
				{
					SWAP(ptr[m], ptr[i], T);
				}
			}
		}
		template<class T> void quickSort(T*ptr, int len, int(*cmp)(const void*, const void*)) {
			if (len <= 4)
			{
				selectSort(ptr, len, cmp);
				return;
			}
			int l = 0;
			int r = len - 1;
			for (int i = 1; i <= r; )
			{
				int c = cmp(&ptr[l], &ptr[i]);
				if (c > 0)
				{
					SWAP(ptr[l], ptr[i], T);
					l++;
					i++;
				}
				else if (c < 0)
				{
					SWAP(ptr[r], ptr[i], T);
					r--;
				}
				else
				{
					i++;
				}
			}

			quickSort(ptr, l, cmp);
			quickSort(ptr + r + 1, len - r - 1, cmp);
		}
		template<class T> void randomizedQuickSort(T*ptr, int len, int(*cmp)(const void*, const void*)) {
			random::randomize(ptr, len);
			quickSort(ptr, len, cmp);
		}
	}
}


#include<vector>
#include<deque>
using std::vector;
using namespace dalt::io;
typedef struct _Node *Node;
struct _Node {
	vector<Node> children;
	int num;
	int id;
	int size;
	int version;
} nodes[200001];



vector<Node> numSet[200001];
ll appearance[200001];

void travel(Node node, Node head, int version)
{
	head->size++;
	node->version = version;
	for (int i = 0, until = node->children.size(); i < until; i++)
	{
		Node nearby = node->children[i];
		if (nearby->version == version)
		{
			continue;
		}
		if (nearby->num % version == 0)
		{
			travel(nearby, head, version);
		}	
	}
}

void solve() {
	int n = readUnsignedInt();
	for (int i = 1; i <= n; i++)
	{
		nodes[i].num = readInt();
		numSet[nodes[i].num].push_back(nodes + i);
		nodes[i].id = i;
	}

	for (int i = 1; i < n; i++)
	{
		Node a = nodes + readInt();
		Node b = nodes + readInt();
		a->children.push_back(b);
		b->children.push_back(a);
	}

	appearance[1] = (ll)n * (n - 1) / 2 + n;

	for (int i = 2; i <= 200000; i++)
	{
		for (int j = i; j <= 200000; j += i)
		{
			vector<Node> &vec = numSet[j];
			for (int k = 0, until = vec.size(); k < until; k++)
			{
				Node node = vec[k];
				if (node->version == i)
				{
					continue;
				}
				node->size = 0;
				travel(node, node, i);
				appearance[i] += (ll)node->size * (node->size + 1) / 2;
			}
		}
	}

	for (int i = 200000; i >= 1; i--)
	{
		for (int j = i + i; j <= 200000; j += i)
		{
			appearance[i] -= appearance[j];
		}
	}

	for (int i = 1; i <= 200000; i++)
	{
		if (appearance[i] == 0)
		{
			continue;
		}

		writeInt(i);
		write(' ');
		writeLong(appearance[i]);
		write('\n');
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("E:\\DATABASE\\TESTCASE\\codeforces\\Contest45G.in", "r", stdin);
	freopen("E:\\DATABASE\\TESTCASE\\codeforces\\Contest45G.out", "w", stdout);
#endif

	solve();
	flush();
	return 0;
}
#endif