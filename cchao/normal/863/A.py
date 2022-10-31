s = raw_input().strip('0')
print ['NO', 'YES'][s == s[::-1]]