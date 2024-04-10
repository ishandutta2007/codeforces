x=readline()
if(x.search(/[a-z]/)>=0 && x.search(/[A-Z]/)>=0 && x.search(/[0-9]/)>=0 && x.length >= 5)
    print('Correct')
else
    print('Too weak')