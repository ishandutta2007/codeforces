MOD = 10 ** 9 + 7

def mod_mul(a, b):
    return (a * b) % MOD

fact = [1]
for i in range(1, 6 * 10 ** 5):
    fact.append(mod_mul(i, fact[-1]))

m = int(input())
c = list(map(int, input().split()))

arr = [0] * 2000010

for v in c:
    val = v - 1
    arr[val+2] += -1
    arr[-val] += 1
    
pos = 0
out = 0
ct = 1
for v in range(-1000000,1000001):
    now = arr[v]
    
    left = pos
    right = pos + now - 1
    
    out += mod_mul(v, ((left + right) * now)//2)
    out %= MOD
    pos += now
    ct = mod_mul(ct, fact[now])
    
    arr[v+2] += now
    
print(out, ct)