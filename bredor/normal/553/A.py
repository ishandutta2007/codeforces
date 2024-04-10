def fuck(n):
    yazhka = 1
    for i in range(1, n + 1):
        yazhka *= i
    return yazhka

def C(n, k):
    return fuck(n) / fuck(k) / fuck(n - k)

k = int(raw_input())
ca = 1
cm = 0
sasai = 1000000007
for i in xrange(k):
    t = int(raw_input())
    cm += t
    ca *= C(cm - 1, t - 1)
    ca %= sasai
print ca