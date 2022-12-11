input()
s = input()

def vowel(c):
    ret = True
    try:
        'aeiouy'.index(c)
    except:
        ret = False
    return ret

while True:
    t = s[0]
    for i in range(1, len(s)):
        if not vowel(s[i - 1]) or not vowel(s[i]):
            t += s[i]
    if s == t: break
    else: s = t

print(s)